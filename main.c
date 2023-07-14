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

// main for read from file test
int main(void) {
    char *line;
    int fd;

    fd = open("text.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    
    return 0;
}

//main for standart input test
// int main() {
//     char *line;

//     while ((line = get_next_line(0)) != NULL) {
//         printf("%s\n", line);
//         free(line);
//     }
//     return 0;
// }