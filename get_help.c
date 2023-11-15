#include "shell.h"

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
