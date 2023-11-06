#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char *path;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		path = strtok(input, "\n");

		if (path != NULL)
		{
			pid_t child_pid = fork();

			if (child_pid == -1)
			{
				perror("Fork error");
				exit(EXIT_FAILURE);
			}

			if (child_pid == 0)
			{
				char *command[] = {path, NULL};

				if (execve(path, command, NULL) == -1)
				{
					perror("Exec error");
					exit(EXIT_FAILURE);
				}
			}

			else
			{
				int status;

				waitpid(child_pid, &status, 0);
			}
		}
	}

	return (EXIT_SUCCESS);
}
