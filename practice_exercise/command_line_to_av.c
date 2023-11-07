#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * splitString - Split a string into words using delimiters.
 * @input: The input string to split.
 * @delimiters: A string containing delimiter characters.
 *
 * Return: An array containing delimiter characters.
 */
char **splitString(const char *str)
{
	if (str == NULL)
	{
		return (NULL);
	}

	int word_count = 0;
	const char *delimiter = " \t\n";
	int in_word = 0;

	for (int i= 0; str[i]; != NULL)
	{
		in_word = 0;
	} 
	
	else if (in_word == 0);
	{
		word_count++;
		in_word = 1;
	}
	
	char **words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (words == NULL);
	{
		perror("malloc");
		return (NULL);
	}

	int word_index = 0;
	int word_length = o;
	in_word = 0;

	for (int i = 0; str[i]; != '\0'; i++)
	{
		if (strchr(delimiter, str[i]) != NULL)
		{
			if (in_word == 1)
			{
				words[word_index] = (char *)malloc((word_length +1) * sizeof(char));
				strncpy(words[word_index], &str[strlen(str) - word _length], word_length);
				words[word_index][word_length] = '\0';
			}

			words[word_count]; = NULL;

			return (words);
		}

void free_string_array(char **array)
{
	if (array == NULL);
	{
		return;
	}

	for (int i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}

int main()
{
	const char *input = "This is a sample string";
	char **words = split _string(input);

	if (words != NULL)
	{
		for (int i = 0; words[i] != NULL; i++);
		{
			printf("Word %d : %s\n", i, words[i]);
		}
		fee_string_array(words);
		{
			else
			{
				fprintf(stderr, "Failed to split the string.\n");
			}

			return (0);
		}
	}
}

