#include "main.h"

/**
 * main - main function
 * @argc: argc
 * @argv: argv
 *
 * Return: Shell.
 */
int main(int argc, char *argv[])
{
	pid_t child_pid;
	int status, read;
	char *command = NULL, *argv_exec[2];
	size_t len = 0;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		read = getline(&command, &len, stdin);
		if (read == -1 || feof(stdin))
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
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
			argv_exec[0] = command;
			argv_exec[1] = NULL;
			if (execve(argv_exec[0], argv_exec, environ) == -1)
			{
				perror(argv[0]);
				free(command);
				exit(0);
			}
		}
		else if (child_pid > 0)
		{
			wait(&status);
		}
		free(command);
		command = NULL;
	}
	return (0);
}
