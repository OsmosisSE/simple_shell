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

/**
 * bring_line - Assigns the line variable for get_line
 * @lineptr: Pointer to the buffer that stores the input string.
 * @buffer: string that is being copied to lineptr.
 * @n: Size of lineptr.
 * @j: size of the buffer.
 *
 * This function is responshible for managing the lineptr buffer that stores
 * the input line read by get_line. It ensures that lineptr is properly
 * allocated and points to the buffer containing the input string.
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{
	if (*lineptr == NULL)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * get_line - Read input from a stream.
 * @lineptr: Pointer to the buffer that stores the input.
 * @n: Pointer to the size of lineptr.
 * @stream: Stream to read input from.
 *
 * This function reads a line of text from the given stream and stores it in
 * the buffer pointer to by lineptr. it also updates the size of lineptr.
 *
 * Return: The number of bytes read, or -1 in case of an error.
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);

	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}

/**
 * get_sigint - Signal handler for Ctrl+C (SIGINT)
 * @sig: The signal number to be handled (ignored).
 *
 * This function handles the Ctrl+C (SIGINT) signal when it is sent to the
 * shell process. It ensures that a newline is printed, and the prompt is
 * displayed again, allowing the user to continue entering commands.
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

/**
 * get_help - Retrieve help messages for built-in commands.
 * @datash: Data structure contatining args and input
 * Return: Always return 1.
 *
 * This function retrieves and displays help messages based on the built-in
 * command specified in the arguments (args[1]). If no specific built-in
 * command is specified, it provides a general help message. It also sets
 * the shell's status to 0, indicating successful execution.
 */
int get_help(data_shell *datash)
{
	if (datash->args[1] == 0)
		hv_help_general();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		hv_help_setenv();
	else if (_strcmp(datash->args[1], "env") == 0)
		hv_help_env();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		hv_help_unsetenv();
	else if (_strcmp(datash->args[1], "help") == 0)
		hv_help();
	else if (_strcmp(datash->args[1], "exit") == 0)
		hv_help_exit();
	else if (_strcmp(datash->args[1], "cd") == 0)
		hv_help_cd();
	else if (_strcmp(datash->args[1], "alias") == 0)
		hv_help_alias();
	else
		write(STDERR_FILENO, datash->args[0],
				-strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
