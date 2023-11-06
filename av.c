#include <stdio.h>

/**
 * main - Entry point.
 * @argc: The number of command-lines in the arguments.
 * @argv: An array containing the command-line arguments
 *
 * Description: The function prints all command-line arguments.
 *
 * Return: 0 (Success).
 */
int main(int argc, char *argv[])
{
	if (argv > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			printf("%s\n", argv[i]);
		}
		else
		{
			printf("No command-line arguments provided.\n");
		}

		return (0);
	}
}
