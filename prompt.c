#include "main.h"

/**
 * prompt - Displays a prompt to the user
 *
 * This function checks if the standard input is a terminal. If it is,
 * it displays a prompt to the user. This is useful for interactive programs
 * that need to indicate to the user that they are waiting for input.
 */

void prompt(void)
{
	/* Check if the standard input is a terminal */
	if (isatty(STDIN_FILENO))
	{
		/* If it is, display a prompt to the user */
		printf("#cisfun$ ");
	}
}
