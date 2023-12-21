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

	set_sigint_handler();

	while (1)
	{
		prompt();

		if (read_command(&command, &len) == NULL)
		{
			if (feof(stdin))
			{
				free_command_cache();
				exit(0);
			}
			continue;
		}

		argv_exec = parse_command(command);

		if (argv_exec == NULL || argv_exec[0] == NULL)
		{
			free(argv_exec);
			free(command);
			command = NULL;
			continue;
		}

		if (strcmp(argv_exec[0], "exit") == 0)
		{
			builtin_exit(argv_exec);
		}
		else if (strcmp(argv_exec[0], "env") == 0)
		{
			print_env();
		}
		else
		{
			execute_command(argv_exec);
		}

		free(argv_exec);
		free(command);
		command = NULL;
	}

	free_command_cache();

	return (0);
}
