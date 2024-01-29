#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

// read from text
int	main(void)
{
    char *line;
    int fd;
    int count;

    count = 0;
    fd = open("text.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        count++;
        printf("[%d]:%s", count, line);

        // print length
        size_t len = ft_strlen(line);
        printf(" (length: %zu)", len);

        // check for \n and NULL at the end of the line
        if (len > 0 && line[len - 1] == '\n')
            printf(" [newline]");
        if (line[len] == '\0')
            printf(" [null-terminated]\n");

        free(line);
    }
    close(fd);
    return (0);
}

// read from std input
/* int main()
{
    char *line;

    while ((line = get_next_line(0)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    return 0;
} */

// bonus main reads 2 files line by line in turn
/* int main()
{
    char *line;
    int fd1, fd2;
    int res1, res2;

    // open files
    fd1 = open("text.txt", O_RDONLY);
    fd2 = open("bonus.txt", O_RDONLY);

    while (1)
    {
        res1 = 1;
        res2 = 1;

        line = get_next_line(fd1);
        if (line)
        {
            printf("FD1: %s", line);
            free(line);
        }
        else
            res1 = 0;

        line = get_next_line(fd2);
        if (line)
        {
            printf("FD2: %s", line);
            free(line);
        }
        else
            res2 = 0;

        if (res1 == 0 && res2 == 0)
            break;
    }

    close(fd1);
    close(fd2);
    return 0;
} */