#include "main.h"

/**
 * prompt - Display a prompt to the user
 *
 * This function displays a prompt to the user. The prompt is displayed only
 * if the standard input is a terminal. The function uses isatty to check if
 * the standard input is a terminal and printf to display the prompt.
 */
void prompt(void)
{
	/* Check if the standard input is a terminal */
	if (isatty(STDIN_FILENO))
	{
		/* If it is, display the prompt */
		printf("#cisfun$ ");
	}
}
