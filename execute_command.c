#include "main.h"

/**
 * execute_command - Execute a command with arguments
 * @argv_exec: Null-terminated array of arguments
 *
 * Return: 0 on success, or -1 on failure
 */
int execute_command(char **argv_exec)
{
	pid_t child_pid;

	if (access(argv_exec[0], X_OK) == -1)
	{
		fprintf(stderr, "%s: No such file or directory\n", argv_exec[0]);
		return (-1);
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		free(argv_exec[0]);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(argv_exec[0], argv_exec, environ) == -1)
		{
			free(argv_exec[0]);
			exit(0);
		}
	}
	else if (child_pid > 0)
	{
		wait(NULL);
	}

	return (0);
}
