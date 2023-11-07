#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_COMMAND 1024
#define MAX_ARGS 32

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *path;

	while (1)
	{
		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		char* args[MAX_ARGS];
		int arg_count = 0;

		char* token = strtok(input, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			if (arg_count >= MAX_ARGS -1)
			{
				fprintf(stderr, "Too many arguments.\n");
				break;
			}
			token = strtok(NULL, " ");
		}

		args[arg_count] = NULL;

		if (arg_count > 0)
		{
			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					perror("execvp");
					exit(EXIT_FAILURE);
				}
				else
				{
					int status;

					waitpid(child_pid, &status, 0);
					if (WIFEXITED(status))
					{
						int exit_status = WEXITSTATUS(status);
						printf("Child process exited with status %d\n", exit_status);
					}
				}
			}
			
			return (0);
		}
	}
}
