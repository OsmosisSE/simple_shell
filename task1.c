#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd>

#define MAX_INPUT 1024

/**
 * main - Entry point.
 *
 * Return: 0.
 */
int main(void)
{
	char input[MAX_INPUT];

	printf("simple_shell$ ");
	if (!fgets(input, MAX_INPUT, stdin))
	{
		break;
	}

	input[strcspn(input, "\n")] = '\0';

	char *token = strtok(input, " ");

	if (token == NULL)
	{
		continue;
	}

	if (strcmp(token, "exit") == 0)
	{
		exit(0);
	}

	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		execlp(token, token, NULL);
		perror("Exec failed");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
