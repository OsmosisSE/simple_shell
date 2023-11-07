#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Entry point.
 *
 * Return: 0.
 */
int main(void)
{
	printf("Current process:%d\n Parent Process:%d\n", getpid(), getppid());

	return (0);
}
