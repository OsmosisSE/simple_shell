#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
	if (argv < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	char *path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not set.\n");
		return (1);
	}

	char *token = strtok(path, ":");

	while (token != NULL)
	{
		for (int i = 1; i < argc; i++)
		{
			char full_path[1024];

			snprintf(full_path, sizeof(full_path), "%s/%s", token, argv[i]);

			if (access(full_path, F_OK) != -1)
			{
				printf("%s\n", full_path);
			}
		}
		token = strtok(NULL, ":");
	}

	return (0);
}
