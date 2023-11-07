#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	if (argv < 2)
	{
		printf(stderr, "Usage: %s filename ...\n", argv[0]);
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

			if (access(full_path, F_OK) == 0)
			{
				printf("%s\n", full_path);
			}
		}
		token = strtok(NULL, ":");
	}

	return (0);
}
