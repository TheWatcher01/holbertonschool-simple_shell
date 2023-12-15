#include "main.h"
/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * This function is the entry point for the shell. It displays a prompt to the
 * user, reads a command from the user, parses the command into arguments,
 * executes the command, and then repeats this process in a loop until the
 * user enters EOF (Ctrl-D).
 *
 * Return: 0 on success, or the exit status of the command on failure
 */
int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t len = 0;
	char **argv_exec;

	/* Ignore unused variable warnings */
	(void)argc;
	(void)argv;

	while (1)
	{
		/* Display the prompt */
		prompt();

		/* Read a command from the user */
		if (read_command(&command, &len) == NULL)
			return (0);

		/* Parse the command into arguments */
		argv_exec = parse_command(command);

		/* Execute the command */
		execute_command(argv_exec);

		/* Free the command and argument vector */
		free(command);
		free(argv_exec);

		/* Reset the command pointer */
		command = NULL;
	}

	/* This point is never reached, but the function needs a return value */
	return (0);
}
