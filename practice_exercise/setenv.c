#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _setenv - Change or add an environment variable.
 * @name: The name of the environment variable.
 * @value: The value to set for the environment variable.
 * @overwrite: A flag to indicate whether to overwrite if the variable
 * already exists.
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || name[0] == '\0' || value == NULL)
		return (-1);

	char *env_var = malloc(strlen(name) + strlen(value) + 2);

	if (env_var == NULL)
		return (-1);

	strcpy(env_var, name);
	strcat(env_var, "=");
	strcat(env_var, value);

	if (overwrite || getenv(name) == NULL)
	{
		if (putenv(env_var) != 0)
		{
			free(env_var);
			return (-1);
		}

	}
	else
	{
		free(env_var);
	}

	return (0);
}
