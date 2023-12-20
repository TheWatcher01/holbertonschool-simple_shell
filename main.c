#include "main.h"

/**
 * main - Entry point for the shell
 *
 * Return: 0 on success, or the exit status of the command on failure
 */
int main(void)
{
	char *command = NULL, **argv_exec;
	size_t len = 0;

	while (1)
	{
		prompt();

		if (read_command(&command, &len) == NULL)
		{
			if (feof(stdin))
			{
				exit(0);
			}
			continue;
		}

		argv_exec = parse_command(command);

		execute_command(argv_exec);

		free(command);
		free(argv_exec);

		command = NULL;
	}

	return (0);
}
