#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _unsetenv - Delete an environment variable by name.
 * @name: The name of the environment variable to delete.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
	if (name == NULL || name[0] == '\0' || getenv(name) == NULL)
		return (0);

	size_t name_len = strlen(name);
	size_t env_var_len = name_len + 1;

	char **env = environ;

	while (*env != NULL)
	{
		if (strncmp(*env, name, env_var_len) == 0 && (*env)[env_var_len] == '=')
		{
			char **src = env;
			char **dst = env;

			while (*src != NULL)
			{
				*dst = *src;
				src++;
				dst++;
			}

			*dst = NULL;

			return (0);
		}
		env++;
	}

	return (0);
}
