#include <stdio.h>
#include <string.h>

#define MAX_INPUT 1024

/**
 * main - Entry point.
 *
 * Return: 0.
 */
int main(void)
{
	char input[MAX_INPUT];

	while (1)
	{
		printf("CustomPrompt$ ");
		if (!fgets(input, MAX_INPUT, stdin))
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		printf("You entered: %s\n", input);
	}

	printf("Goodbye!\n");
	return (0);
}
