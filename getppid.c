#include <stdio.h>
#include <stdlib.h>

/**
 * main - get the parent process id.
 *
 * Return: 0
 */
int main(void)
{
	pid_t parent_pid = getppid();

	printf("Parent PID:%d\n", parent_pid);

	return (0);
}
