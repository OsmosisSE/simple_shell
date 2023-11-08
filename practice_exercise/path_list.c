#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path_list.h"

/**
 * build_path_list - Build a linked list of directories from the path variable.
 *
 * Return: A pointer to the head of a linked list, or NULL on failure.
 */
struct DirectoryList *build_path_list(void)
{
	char *path = getenv("PATH");

	if (path == NULL)
		return (NULL);

	struct DirectoryList *head = NULL;
	struct DirectoryList *current = NULL;

	char *token = strtok(path, ":");

	while (token != NULL)
	{
		struct DirectoryList *new_node = malloc(sizeof(struct DirectoryList));

		if (new_node == NULL)
		{
			return (NULL);
		}

		new_node->dir = strdup(token);
		new_node->next = NULL;

		if (current == NULL)
		{
			head = new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}

		token = strtok(NULL, ":");
	}

	return (head);
}
