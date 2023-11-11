#include "shell.h"

/**
 * exec_line - Excutes built-in commands or external commands.
 *
 * @datash: Data structure containing relevant information (args).
 * Return: 1 on success.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}

/**
 * get_builtin - Retrieves the function pointer for a built-in command.
 *
 * @cmd: Command string.
 * Return: Function pointer of the built-in command.
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f);
}

/**
 * get_error - Calls the appropriate error function based on the error code.
 *
 * @datash: Data structure containing arguments.
 * @eval: Error value.
 * Return: Error value.
 */
int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = error_env(datash);
			break;
		case 126:
			error = error_path_126(datash);
			break;
		case 127:
			error = error_not_found(datash);
			break;
		case 2:
			if (_strcmp("exit", datash->args[0]) == 0)
				error = error_exit_shell(datash);
			else if (_strcmp("cd", datash->args[0]) == 0)
				error = error_get_cd(datash);
			break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}

/**
 * exit_shell - Exists the shell.
 *
 * @datash: Data structure containing stauts and arges.
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (ustatus % 256);
	}
	return (0);
}
