#include "main.h"

/**
 * prompt - Display a prompt to the user
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("#cisfun$ ");
	}
}
