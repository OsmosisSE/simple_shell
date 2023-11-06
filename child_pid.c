#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Child process id.
 *
 * Return: 0.
 */
int main(void)
{
	int i;
	pid_t child_pid;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid < 0)
		{
			perror("Fork error");
			exit(1);
		}
		else if (child_pid == 0)
		{
			execlp("ls", "ls", "/tmp", NULL);

			perror("Exec error");
			exit(1);
		}
		else
		{
			int status;

			waitpid(child_pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			{
				printf("Child %d has exited successfully.\n", i + 1);
			}

			else
			{
				printf("Child %d has exited with an error.\n", i + 1);
			}
		}
	}

	return (0);
}
