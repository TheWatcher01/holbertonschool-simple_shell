#include "main.h"
/**
 * main - Entry point (simple shell example)
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	char command[1024];
	char *argv[2];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(command, 1024, stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}
		command[strcspn(command, "\n")] = 0;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			argv[0] = command;
			argv[1] = NULL;
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(command);
				exit(0);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
