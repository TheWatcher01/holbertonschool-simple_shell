#include "main.h"
/**
 * read_command - Reads a command from the user
 *
 * Function reads line from standard input using getline,
 * stores it in command string. It also removes newline character
 * from end of command. If an error occurs or if
 * the end of file is reached, it frees the command string and returns NULL.
 *
 * Return: Command string, or NULL if an error occurs or if the end
 * of file is reached.
 */
char *read_command(void)
{
	char *command = NULL;
	size_t len = 0;

	if (getline(&command, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}

	command[strcspn(command, "\n")] = 0;

	return (command);
}
