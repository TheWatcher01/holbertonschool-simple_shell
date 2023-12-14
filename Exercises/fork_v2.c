#include "main.h"

/**
 * main - Entry point (fork example)
 *
 * Description: This program demonstrates the use of fork function.
 * It creates a child process and prints a message before and after the fork.
 * It also prints the process ID of the current process.
 *
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	my_pid = getpid();

	printf("My pid is %u\n", my_pid);

	if (child_pid == 0)
	{
		printf("(%u) Nooooooooo!\n", my_pid);
	}
	else
	{
		printf("(%u) %u, I am your father\n", my_pid, child_pid);
	}

	return (0);
}
