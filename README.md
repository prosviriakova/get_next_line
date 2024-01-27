# get_next_line

```
FINAL GRADE: 
```

 A function that reads a line from a file descriptor and returns it, allowing line-by-line reading of a text file.
 The buffer size can be varied during compilation.
 
| Function name    | get_next_line                       |
|:-----------------|:------------------------------------|
| Prototype        | `char *get_next_line(int fd);`      |
| Turn in files    | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| Parameters       | fd: The file descriptor to read from |
| Return value     | Read line: correct behavior<br>NULL: there is nothing else to read, or an error occurred |
| External functs. | read, malloc, free                  |
| Libft authorized | No                                  |
| Description      | Write a function that returns a line read from a file descriptor |

> To compile the program with main.c and read from a text file with a custom buffer size, use the following command:<br>
> `gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c get_next_line.h main.c -o gnl`

> To read from standard input, compile the program and run it. Then, type your text in the console and interrupt the input stream with Ctrl+D (EOF).

> To redirect input from one file to another, execute: 
> `./gnl < text.txt > output.txt`

There are two versions of the get_next_line() function.
* The mandatory version, which requires a file descriptor as a parameter.
* The bonus version, which allows the management of multiple file descriptors simultaneously.

The project has been tested with the following testers:
- [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
- [kodpe/gnl-station-tester](https://github.com/kodpe/gnl-station-tester)

Subject version: 12.
