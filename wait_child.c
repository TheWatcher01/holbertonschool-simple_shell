#include "main.h"

int wait_child(echo "/bin/ls" | ./shell)
{
	int status;

	if (wait(&status) == -1)
	{
		perror("wait error");
		exit(EXIT_FAILURE);
	}

	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status))
	{
		return (WTERMSIG(status));
	}
	else if (WIFSTOPPED(status))
	{
		return (WSTOPSIG(status));
	}

	return (0);
}
