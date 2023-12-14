#include "main.h"

/**
 * main - Entry point (fork and wait example)
 *
 * Description: This program demonstrates the use of fork and wait functions.
 * It creates a child process that sleeps for 3 seconds and prints a message.
 * Parent process waits for child to finish before printing its own message.
 *
 * Return: 0 on success, 1 on error.
 */

int main(void)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid ==  -1)
	{
		perror("Error:");
		return (1);
	}

	if (child_pid == 0)
	{
		printf("Wait for me, wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}
