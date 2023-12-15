#include "main.h"
/**
 * execute_command - Execute a command with arguments
 * @argv_exec: Null-terminated array of arguments
 *
 * This function takes a null-terminated array of arguments as input and
 * executes the command specified by the first argument. The remaining
 * arguments are passed to the command. The function uses fork to create a
 * new process and execve to replace the new process with the command to be
 * executed. If the command cannot be executed, an error message is printed
 * and the program exits.
 */
void execute_command(char **argv_exec)
{
	pid_t child_pid;

	/* Create a new process */
	child_pid = fork();

	if (child_pid == -1)
	{
		/* If fork failed, print an error message and exit */
		perror("Error:");
		free(argv_exec[0]);
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* In the child process, replace the process with the command */
		if (execve(argv_exec[0], argv_exec, environ) == -1)
		{
			/* If execve failed, print an error message and exit */
			fprintf(stderr, "%s: No such file or directory\n", argv_exec[0]);
			free(argv_exec[0]);
			exit(0);
		}
	}
	else if (child_pid > 0)
	{
		/* In the parent process, wait for the child to finish */
		wait(NULL);
	}
}
