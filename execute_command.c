#include "main.h"
/**
 * execute_command - Execute a command
 * @argv_exec: The command to execute
 *
 * Return: 0 on success, or the exit status of the command on failure.
 */
void execute_command(char **argv_exec)
{
	pid_t child_pid;
	int status;

	/* Check if the command is "exit" */
	if (strcmp(argv_exec[0], "exit") == 0)
	{
		/* If it is, terminate the shell */
		free(argv_exec);
		exit(0);
	}

	/* Create a new process */
	child_pid = fork();

	if (child_pid == -1)
	{
		/* If fork failed, print an error message and exit */
		perror("Error:");
		free(argv_exec);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* In the child process, replace the process with the command */
		if (execve(argv_exec[0], argv_exec, environ) == -1)
		{
			/* If execve failed, print an error message and exit */
			fprintf(stderr, "./hsh: %s: No such file or directory\n", argv_exec[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		/* In the parent process, wait for the child to finish */
		if (wait(&status) == -1)
		{
			perror("wait error");
			free(argv_exec);
			exit(EXIT_FAILURE);
		}
	}
}
