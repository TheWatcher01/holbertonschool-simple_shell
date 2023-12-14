#include "main.h"

/**
 * split_string - Function that splits a string and returns an array of each
 * word of string.
 * @str: The string to split.
 * Return: A pointer to an array of pointers to the words.
 */

char **split_string(char *str)
{
	char **words = malloc(128 * sizeof(char *));
	char *word;
	int i = 0;

	word = strtok(str, " ");
	while (word != NULL)
	{
		words[i] = word;
		i++;
		word = strtok(NULL, " ");
	}
	words[i] = NULL;

	return (words);
}
