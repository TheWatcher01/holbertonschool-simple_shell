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
	/* Declare a variable to hold the process ID of the current process */
	pid_t my_pid;

	/* Declare a variable to hold process ID of new process created by fork */
	pid_t pid;

	/* Print a message before the fork */
	printf("Before fork\n");

	/* Create a child process */
	pid = fork();

	/* Check if fork was successful */
	if (pid == -1)
	{
		/* Print an error message and return 1 if fork fails */
		perror("Error:");
		return (1);
	}

	/* Print a message after the fork */
	printf("After fork\n");

	/* Get the process ID of the current process */
	my_pid = getpid();

	/* Print the process ID */
	printf("My pid is %u\n", my_pid);

	/* Return 0 to indicate successful execution */
	return (0);
}
