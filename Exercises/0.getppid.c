#include "main.h"

/**
 * main - Entry point
 *
 * Description: This program prints the process ID of the parent process.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	/* Get the process ID of the parent process */
	pid_t ppid = getppid();

	/* Print the parent process ID */
	printf("PID du processus parent : %d\n", ppid);

	/* Return 0 to indicate successful execution */
	return (0);
}
