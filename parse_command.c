#include "main.h"

/**
 * parse_command - Parse a command into arguments
 * @command: The command to parse
 *
 * This function takes a command as input and parses it into an array of
 * arguments. It does this by splitting the command at each space character.
 * The resulting array of arguments is null-terminated and can be used as
 * input to execve.
 *
 * Return: A null-terminated array of arguments
 */
char **parse_command(char *command)
{
	char **argv_exec = malloc(64 * sizeof(char *));
	char *token = strtok(command, " ");
	int i = 0;

	/* Loop over each token in the command */
	while (token != NULL)
	{
		/* Add the current token to the array of arguments */
		argv_exec[i] = token;
		i++;

		/* Get the next token */
		token = strtok(NULL, " ");
	}

	/* Null-terminate the array of arguments */
	argv_exec[i] = NULL;

	return (argv_exec);
}
