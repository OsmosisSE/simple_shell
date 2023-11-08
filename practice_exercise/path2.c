#include "path_list.h"

/**
 * struct DirectoryList - simply linked list of directory nodes.
 * @dir: A directory in the PATH.
 * @next: Points to the next node in the list
 */
typedef struct DirectoryList
{
	char *dir;
	struct DirectoryList *next;
}
DirectoryList;

/**
 * build_path_list - Build a linked list of directories from the PATH variable.
 *
 * Return: A pointer to the head of the linked list, or NULL on failure.
 */
DirectoryList *build_path_list(void)
{
	char *path = getenv("PATH");

	if (path == NULL)
		return (NULL);

	DirectroyList *head = NULL;
	DirectoryList *current = NULL;

	char *token = strtok(path, ":");

	while (token != NULL)
	{
		DirectoryList *new_node = malloc(sizeof(DirectoryList));

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
