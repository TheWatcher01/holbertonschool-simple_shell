#include "main.h"
/**
 * execute_command - Executes a command in a new process
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t child_pid;
	char *argv_exec[2];

	/* Initialize the argv_exec array */
	argv_exec[0] = command;
	argv_exec[1] = NULL;

	/* Create a new process */
	child_pid = fork();

	/* Check if the fork call was successful */
	if (child_pid == -1)
	{
		perror("Error:");
		free(command);
		exit(EXIT_FAILURE);
	}
	/* Check if this is the child process */
	else if (child_pid == 0)
	{
		/* Execute the command in the new process */
		if (execve(argv_exec[0], argv_exec, environ) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", command);
			free(command);
			exit(0);
		}
	}
	/* Check if this is the parent process */
	else if (child_pid > 0)
	{
		/* Wait for the child process to finish */
		wait(NULL);
	}
}
