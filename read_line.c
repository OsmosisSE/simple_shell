#include "shell.h"

/**
 * read_line - Reads and retrieves user input from stdin.
 *
 * @i_eof: A pointer to store the return value of getline function.
 *
 * Return: A pointer to the input string read from the user.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
