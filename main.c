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
	int exec_status;

	(void)argc;
	(void)argv;

	while (1)
	{
		prompt();

		if (read_command(&command, &len) == NULL)
			return (0);

		argv_exec = parse_command(command);

		if (strcmp(argv_exec[0], "exit") == 0)
		{
			free(command);
			free(argv_exec);
			exit(0);
		}
		else if (strcmp(argv_exec[0], "env") == 0)
		{
			print_env();
		}
		else
		{
			exec_status = execute_command(argv_exec);
			if (exec_status != 0)
			{
				perror(argv_exec[0]);
			}
		}

		free(command);
		free(argv_exec);

		command = NULL;
	}

	return (0);
}
