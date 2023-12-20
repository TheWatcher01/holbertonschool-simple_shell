#include "main.h"

/**
 * execute_external_command - Execute an external command
 * @argv_exec: Null-terminated array of arguments
 *
 * Return: 0 on success, or -1 on failure
 */
int execute_external_command(char **argv_exec)
{
	pid_t child_pid;
	char *command_path = get_command_path(argv_exec[0]);

	if (!command_path)
	{
		handle_error("Error: Command not found", NULL);
		return (-1);
	}

	child_pid = create_process();

	if (child_pid == -1)
	{
		handle_error("Error: Failed to fork", command_path);
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (access(command_path, F_OK) != 0)
		{
			handle_error("Error: Command not found", command_path);
			exit(EXIT_FAILURE);
		}
		if (execve(command_path, argv_exec, environ) == -1)
		{
			handle_error("Error: Failed to execute command", command_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		wait_for_process(child_pid);
	}

	free(command_path);
	return (0);
}

/**
 * execute_command - Execute a command with arguments
 * @argv_exec: Null-terminated array of arguments
 *
 * Return: 0 on success, or -1 on failure
 */
int execute_command(char **argv_exec)
{
	if (check_builtin(argv_exec) == 0)
	{
		return (execute_builtin_command(argv_exec));
	}

	return (execute_external_command(argv_exec));
}
