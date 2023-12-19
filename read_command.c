#include "main.h"
/**
 * read_command - Reads a command from the user
 * @command: A pointer to the command string
 * @len: A pointer to the length of the command
 *
 * Return: Command string, or NULL if an error occurs or if the end
 * of file is reached.
 */
char *read_command(char **command, size_t *len)
{
	ssize_t read;

	read = getline(command, len, stdin);

	if (read == -1 || feof(stdin))
	{
		if (isatty(STDIN_FILENO))
		{
			putchar('\n');
		}
		free(*command);
		*command = NULL;
		return (NULL);
	}

	(*command)[strcspn(*command, "\n")] = 0;

	if ((*command)[0] == '\0')
	{
		free(*command);
		*command = NULL;
	}

	return (*command);
}
