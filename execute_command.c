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

	if (execute_builtin_command(argv_exec) != -1)
	{
		return (0);
	}

	if (!argv_exec[0])
	{
		return (0);
	}

	if (argv_exec[0][0] == '/' || strncmp(argv_exec[0], "./", 2) == 0)
	{
		command_path = strdup(argv_exec[0]);
		if (!command_path)
		{
			handle_error("Error: Failed to allocate memory", NULL);
			return (-1);
		}
	}
	else
	{
		char *cached_path = get_from_cache(argv_exec[0]);
		if (cached_path)
		{
			command_path = strdup(cached_path);
		}
		else
		{
			command_path = get_command_path(argv_exec[0]);
			if (command_path)
			{
				add_to_cache(argv_exec[0], command_path);
			}
			else
			{
				handle_error("Error: Command not found", NULL);
				return (-1);
			}
		}
	}

	if (!command_path)
	{
		errno = ENOENT;
		return (-1);
	}

	child_pid = fork();

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
		wait(NULL);
	}

	free(command_path);
	return (0);
}
