/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:28:48 by oprosvir          #+#    #+#             */
/*   Updated: 2023/07/12 22:28:48 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char    *buff;
    ssize_t bytesRead;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    while ((bytesRead = read(fd, buff, BUFFER_SIZE - 1)) > 0)
        buff[bytesRead] = '\0'; // Add null-terminator    
    return buff;
}