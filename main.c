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
		if (is_interactive())
		{
			prompt();
		}

		if (read_command(&command, &len) == NULL)
		{
			if (is_interactive())
			{
				printf("\n");
			}
			if (command)
			{
				free(command);
				command = NULL;
			}
			exit(EXIT_SUCCESS);
		}

		argv_exec = parse_command(command);

		if (argv_exec == NULL)
		{
			if (command)
			{
				free(command);
				command = NULL;
			}
			continue;
		}

		if (strcmp(argv_exec[0], "exit") == 0)
		{
			free(command);
			free(argv_exec);
			command = NULL;
			argv_exec = NULL;
			break;
		}

		execute_command(argv_exec);

		if (command)
		{
			free(command);
			command = NULL;
		}
		if (argv_exec)
		{
			free(argv_exec);
			argv_exec = NULL;
		}
	}

	return (0);
}
