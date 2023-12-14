#include "main.h"

int main(void)
{
	pid_t child_pid;
	int status;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			char *argv[] = {"/bin/ls", "-1", "/tmp", NULL};
			execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
