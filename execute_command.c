#include "main.h"
/**
 * execute_command - Executes a command in a new process
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t child_pid;
	char *argv_exec[2];

	argv_exec[0] = command;
	argv_exec[1] = NULL;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		free(command);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(argv_exec[0], argv_exec, environ) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", command);
			free(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
