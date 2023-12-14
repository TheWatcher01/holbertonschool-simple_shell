#include "main.h"

/**
 * main - Entry point
 *
 * Description: Program that prints the process ID of the current process.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	/* Declare a variable to hold the process ID */
	pid_t my_pid;

	/* Get the process ID of the current process */
	my_pid = getpid();

	/* Print the process ID */
	printf("%u\n", my_pid);

	/* Return 0 to indicate successful execution */
	return (0);
}
