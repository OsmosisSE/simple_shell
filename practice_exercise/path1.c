#include <stdio.h>
#include <stdlib.h>

/**
 * print_path_directories - Prints each directory in PATH environment variable.
 */
void print_path_directories(void)
{
	char *path = getenv("PATH");

	if (path != NULL)
	{
		char *token = strtok(path, ":");

		while (token != NULL)
		{
			printf("%s:\n", token);
			token = strtok(NULL, ":");
		}
	}

}
