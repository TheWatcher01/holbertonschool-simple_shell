#include "main.h"
/**
 * main - Entry point (simple shell example)
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	pid_t child_pid;
	int status, read;
	char *command = NULL, *argv[2];
	size_t len = 0;

	printf("#cisfun$ ");
	while ((read = getline(&command, &len, stdin)) != -1)
	{
		if (read == -1)
		{
			free(command);
			return (0);
		}
		command[strcspn(command, "\n")] = 0;
		if (command[0] == '\0')
		{
			free(command);
			command = NULL;
			continue;
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			argv[0] = command;
			argv[1] = NULL;
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(command);
				free(command);
				exit(0);
			}
		}
		else if (child_pid > 0)
		{
			wait(&status);
			printf("#cisfun$ ");
		}
		free(command);
		command = NULL;
	}
	printf("\n");
	free(command);
	return (0);
}
