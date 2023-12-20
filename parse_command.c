#include "main.h"

/**
 * parse_command - Parse a command into arguments
 * @command: The command to parse
 *
 * Return: A null-terminated array of arguments
 */
char **parse_command(char *command)
{
	char **argv_exec = malloc(64 * sizeof(char *));
	char *token = strtok(command, " ");
	int i = 0;

	if (!argv_exec)
	{
		perror("Error:");
		return (NULL);
	}

	while (token != NULL)
	{
		argv_exec[i] = token;
		i++;

		token = strtok(NULL, " ");
	}

	argv_exec[i] = NULL;

	return (argv_exec);
}
