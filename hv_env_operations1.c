#include "shell.h"

/**
 * copy_info - Copies info to create a new env or alias.
 * @name: Name (env or alias.
 * @value: Value (env or alias).
 *
 * Return: New env or alias.
 */
char *copy_info(char *name, char *value)
{
	int len_name, len_value, len;
	char *new;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;

	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * _getenv - Get the value of an environment variable.
 * @name: Name of the environment variable.
 * @_environ: Environment variable array.
 *
 * Return: Value of the environment variable if found, otherwise NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;

	for (i = 0; _environ[i]; i++)
	{
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * set_env - Sets an environment variable.
 * @name: Name of the environment variable.
 * @value: Value of the environment variable.
 * @datash: Data structure (environ).
 *
 * Return: No return.
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]);
		name_env = _strtok(var_env, "=");

		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = copy_info(name, value);
	datash->_environ[i + 1] = NULL;
}
