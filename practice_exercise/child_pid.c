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
	for (int i = 0; i < 5; i++)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			printf("Child %d (PID: %d) running ls -l /tmp:\n", i + 1, getpid());
			execl("/bin/ls", "ls", "-l", "/tmp", (char *)0);

			perror("execl");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
			{
				printf("Child %d (PID: %d) completed successfully.\n", i + 1, child_pid);
			}
			else
			{
				printf("Child %d (PID: %d) encountered an error.\n", i + 1, child_pid);
			}
		}
	}

	return (0);
}
