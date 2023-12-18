#include "main.h"
/**
 * read_command - Reads a command from the user
 * @command: A pointer to the command string
 * @len: A pointer to the length of the command
 *
 * Function reads line from standard input using getline,
 * stores it in command string. It also removes newline character
 * from end of command. If an error occurs or if
 * the end of file is reached, it frees the command string and returns NULL.
 *
 * Return: Command string, or NULL if an error occurs or if the end
 * of file is reached.
 */

char *read_command(char **command, size_t *len)
{
	/* Check if the shell is in interactive mode */
	int interactive = isatty(STDIN_FILENO);

	/* Read a line from the standard input */
	int read = getline(command, len, stdin);

	/* Check if an error occurred or if the end of file was reached */
	if (read == -1 || feof(stdin))
	{
		/* If so, free the command string and return NULL */
		if (interactive)
		{
			putchar('\n'); /* Add a newline before exiting */
		}
		free(*command);
		return (NULL);
	}

	/* Remove the newline character from the end of the command */
	(*command)[strcspn(*command, "\n")] = 0;

	/* If the command is empty, free the command string and set it to NULL */
	if ((*command)[0] == '\0')
	{
		free(*command);
		*command = NULL;
	}

	/* Return the command string */
	return (*command);
}
