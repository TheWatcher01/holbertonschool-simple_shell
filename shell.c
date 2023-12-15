#include "main.h"

int main(void)
{
	char *line_usr_cmd = NULL, *argv[2];
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status, is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			printf("#cisfun$ ");
		read = getline(&line_usr_cmd, &len, stdin);
		if (read == -1) /* EOF condition */
		{
			if (is_interactive)
				printf("\n");
			exit(EXIT_SUCCESS);
		}
		line_usr_cmd[read - 1] = '\0'; /* Remove newline at the end */
		argv[0] = line_usr_cmd;
		argv[1] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			continue;
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("./shell");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	free(line_usr_cmd);
	return (EXIT_SUCCESS);
}
