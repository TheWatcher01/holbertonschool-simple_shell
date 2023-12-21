#include "main.h"

/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
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
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			builtin_exit(NULL);
		}

		if (command[0] != '\0')
		{
			argv_exec = parse_command(command);

			if (argv_exec == NULL || argv_exec[0] == NULL)
			{
				free(argv_exec);
				free(command);
				command = NULL;
				continue;
			}

			if (strcmp(argv_exec[0], "env") == 0)
			{
				print_env();
			}
			else
			{
				execute_command(argv_exec);
			}

			free(argv_exec);
		}

		free(command);
		command = NULL;
	}

	return (0);
}
