#include "main.h"
/**
 * execute_command - Execute a command with arguments
 * @argv_exec: Null-terminated array of arguments
 */
void execute_command(char **argv_exec)
{
	pid_t child_pid;

	if (access(argv_exec[0], X_OK) == -1)
	{
		fprintf(stderr, "./hsh: %s: No such file or directory\n", argv_exec[0]);
		return;
	}

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	else if (child_pid == 0)
	{
		if (execve(argv_exec[0], argv_exec, NULL) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		wait(NULL);
	}
}
