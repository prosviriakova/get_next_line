/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:48:03 by oprosvir          #+#    #+#             */
/*   Updated: 2023/07/14 22:48:03 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    char *line;
    int fd;

    fd = open("text.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    
    close(fd);
    
    return 0;
}