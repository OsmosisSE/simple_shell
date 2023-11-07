#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Get line.
 *
 * Return: 0.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (getline(&input, &len, stdin) == -1)
		{
			perror("get line");
			free(input);
			exit(EXIT_FAILURE);
		}

		input[strcspn(input, "\n")] = '0';

		printf("You entered: %s\n", input);

		free(input);
		input = NULL;
	}

	return (0);
}
