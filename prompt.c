#include "main.h"

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
}
