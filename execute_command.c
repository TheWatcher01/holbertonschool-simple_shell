#include "main.h"
/**
 * execute_command - Executes a command
 * @argv_exec: The command to execute
 *
 * Return: Nothing
 */
void execute_command(char **argv_exec)
{
	pid_t child_pid;
	int status;
	char *command_path;

	command_path = get_command_path(argv_exec[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", argv_exec[0]);
		return;
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command_path, argv_exec, environ) == -1)
		{
			perror("Error:");
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("Error:");
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(command_path);
}
