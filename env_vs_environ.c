#include <stdio.h>

/**
 * main - Entry point of the program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings containing the command-line arguments.
 * @env: The array of environment variables.
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	printf("Address of env: %p\n", (void *)env);
	printf("Address of environ: %p\n", (void *)environ);

	if (env == environ)
	{
		printf("env and environ point to the same address.\n");
	}
	else
	{
		printf("env and environ are different.\n");
	}

	return (0);
}
