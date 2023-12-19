#include "main.h"

/**
 * parse_command - Parse a command into arguments
 * @command: The command to parse
 *
 * Return: A null-terminated array of arguments
 */
char **parse_command(char *command)
{
	char **argv_exec = malloc(2 * sizeof(char *));
	char *token = strtok(command, " ");
	if (!argv_exec)
	{
		return (NULL);
	}

	argv_exec[0] = token;
	argv_exec[1] = NULL;

	return (argv_exec);
}
