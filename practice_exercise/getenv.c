#include <stdio.h>
#include <stdlib.h>

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(const char *name)
{
	if (name == NULL)
		return (NULL);

	for (char **env = environ; *env != NULL; env++)
	{
		char *entry = *env;
		char *delimiter = "=";
		char *token = strtok(entry, delimiter);

		if (token != NULL && strcmp(token, name) == 0)
		{
			token = strtok(NULL, delimiter);
			return (token);
		}
	}

	return (NULL);
}
/**
 * main - Entry point.
 *
 * Return: 0.
 */
int main(void)
{
	char *home = _getenv("HOME");

	if (home != NULL)
	{
		printf("HOME: %s\n", home);
	}
	else
	{
		printf("HOME variable not found.\n");
	}

	return (0);
}
