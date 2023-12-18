#include <unistd.h>

/**
 * is_interactive - Check if the shell is in interactive mode
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */
int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}
