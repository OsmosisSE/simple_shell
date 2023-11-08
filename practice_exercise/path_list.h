#ifndef PATH_LIST_H
#define PATH_LIST_H

/**
 * struct DirectoryList - A structure for representing directories
 * in a linked list
 * @dir: The directory path.
 * @next: A pointer to the next DirectoryList node.
 */
struct DirectoryList
{
	char *dir;
	struct DirectoryList *next;
};

typedef struct DirectoryList DirectoryList;

#endif /* PATH_LIST_H */
