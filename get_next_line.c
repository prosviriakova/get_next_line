/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:15:47 by oprosvir          #+#    #+#             */
/*   Updated: 2024/01/28 18:56:04 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_fd(int fd, char *saved, char *buff)
{
	char	*temp;
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buff[bytes_read] = '\0';
		if (!saved)
			saved = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(saved, buff);
			free(saved);
			saved = temp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (saved);
}

static char	*extract_line(char **saved_line)
{
	char	*extracted_line;
	char	*new_line;
	int		i;

	i = 0;
	while ((*saved_line)[i] && (*saved_line)[i] != '\n')
		i++;
	if ((*saved_line)[i] == '\n')
	{
		extracted_line = ft_substr(*saved_line, 0, i + 1);
		new_line = ft_strdup(*saved_line + i + 1);
		free(*saved_line);
		*saved_line = new_line;
	}
	else
	{
		extracted_line = ft_strdup(*saved_line);
		free(*saved_line);
		*saved_line = NULL;
	}
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	saved_line = read_from_fd(fd, saved_line, buff);
	free(buff);
	if (!saved_line || saved_line[0] == '\0')
	{
		free(saved_line);
		saved_line = NULL;
		return (NULL);
	}
	return (extract_line(&saved_line));
}
