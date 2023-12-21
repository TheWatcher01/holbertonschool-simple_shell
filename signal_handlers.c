#include "main.h"

/**
 * sigint_handler - Handles the SIGINT signal
 * @sig: The signal number
 *
 * This function is called when the process receives a SIGINT signal.
 * It writes a new line and the prompt to the standard output.
 */
void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/**
 * set_sigint_handler - Sets the SIGINT signal handler
 *
 * This function sets sigint_handler as the handler for the SIGINT signal.
 * When the process receives a SIGINT signal, it will call sigint_handler
 * instead of terminating the process.
 */
void set_sigint_handler(void)
{
	signal(SIGINT, sigint_handler);
}
