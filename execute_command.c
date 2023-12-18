#include "main.h"
/**
 * execute_command - Executes a command
 * @argv_exec: The command to execute
 * Return: 0 on success, or the exit status of the command on failure
 */
int execute_command(char **argv_exec)
{
	pid_t child_pid;

	exit_command(argv_exec);

	if (strcmp(argv_exec[0], "env") == 0)
	{
		print_env();
		return (0);
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(argv_exec[0], argv_exec, environ) == -1)
		{
			fprintf(stderr, "./hsh: %s: No such file or directory\n", argv_exec[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		return (wait_child());
	}

	return (0);
}
