#include "main.h"
/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, or the exit status of the command on failure
 */
int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t len = 0;
	char **argv_exec;

	(void)argc;
	(void)argv;

	while (1)
	{
		prompt();

		if (read_command(&command, &len) == NULL)
			return (0);

		argv_exec = parse_command(command);

		execute_command(argv_exec);

		free(command);
		free(argv_exec);

		command = NULL;
	}

	return (0);
}
