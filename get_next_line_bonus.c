/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:35:50 by oprosvir          #+#    #+#             */
/*   Updated: 2024/01/24 14:06:49 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_buffer(int fd)
{
	char	*buff;
	int		bytes_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[bytes_read] = '\0';
	return (buff);
}

static char	*process_buffer(char *saved, char *buff)
{
	char	*temp;

	if (!saved)
		saved = ft_strdup(buff);
	else
	{
		temp = ft_strjoin(saved, buff);
		free(saved);
		saved = temp;
	}
	return (saved);
}

static char	*read_from_fd(int fd, char *saved)
{
	char	*buff;

	while (1)
	{
		buff = read_buffer(fd);
		if (!buff)
			break ;
		saved = process_buffer(saved, buff);
		free(buff);
		if (ft_strchr(saved, '\n'))
			break ;
	}
	return (saved);
}

static char	*extract_line(char **saved_line)
{
	char	*line;
	char	*new_saved_line;
	int		i;

	i = 0;
	while ((*saved_line)[i] && (*saved_line)[i] != '\n')
		i++;
	if ((*saved_line)[i] == '\n')
	{
		line = ft_substr(*saved_line, 0, i + 1);
		new_saved_line = ft_strdup(*saved_line + i + 1);
		free(*saved_line);
		*saved_line = new_saved_line;
	}
	else
	{
		line = ft_strdup(*saved_line);
		free(*saved_line);
		*saved_line = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved_line[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	saved_line[fd] = read_from_fd(fd, saved_line[fd]);
	if (!saved_line[fd] || saved_line[fd][0] == '\0')
	{
		free(saved_line[fd]);
		saved_line[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&saved_line[fd]));
}
