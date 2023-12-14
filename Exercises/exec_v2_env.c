#include "main.h"

/**
 * main - Entry point
 *
 * Description: This program demonstrates the use of execve function.
 * It executes the command "/bin/ls -l /usr/" and prints a message
 * before and after the execution.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	/* Declare and initialize the command to be executed */
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	/* Print a message before the execution of the command */
	printf("Before execve\n");

	/* Execute the command and check for errors */
	if (execve(argv[0], argv, environ) == -1)
	{
		/* Print an error message if execve fails */
		perror("Error:");
	}

	/* Print a message after the execution of the command */
	printf("After execve\n");

	/* Return 0 to indicate successful execution */
	return (0);
}
