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
	char *command_path;

	if (argv_exec[0][0] == '/')
	{
		command_path = strdup(argv_exec[0]);
	}
	else
	{
		command_path = get_command_path(argv_exec[0]);
	}

	if (!command_path)
	{
		errno = ENOENT;
		return (-1);
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		free(command_path);
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(command_path, argv_exec, environ) == -1)
		{
			perror(argv_exec[0]);
			free(command_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		wait(NULL);
	}

	free(command_path);
	return (0);
}
