#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char **environ = NULL;

	int i = 0;

	while (environ[1] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}
