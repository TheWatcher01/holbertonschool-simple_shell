#include "main.h"

/**
 * main - Entry point
 *
 * Description: Program that prints "$ ", waits for user to enter a command,
 * and then prints it on the next line.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	/* Declare a pointer to a char array and initialize it to NULL */
	char *line = NULL;

	/* Declare variable to hold length of input and initialize it to 0 */
	size_t len = 0;

	/* Declare a variable to hold the return value of getline */
	ssize_t read;

	/* Print the prompt */
	printf("$ ");

	/* Read a line from stdin */
	read = getline(&line, &len, stdin);

	/* If getline was successful, print the line */
	if (read != -1)
	{
		printf("%s", line);
	}

	/* Free the memory allocated by getline */
	free(line);

	/* Return 0 to indicate successful execution */
	return (0);
}
