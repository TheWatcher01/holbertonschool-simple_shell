#include "main.h"

/**
 * handle_error - Handles errors by printing an error message and exiting the program.
 * @message: The error message to be printed.
 * @mem_to_free: A pointer to the memory to be freed, if any.
 *
 * If mem_to_free is not NULL, the function frees the memory it points to.
 * The function then prints the error message to stderr and exits the program
 * with a failure status.
 */
void handle_error(char *message, char *mem_to_free)
{
	/* If there is any memory to be freed, free it. */
	if (mem_to_free)
	{
		free(mem_to_free);
	}

	/* If the message is NULL, it means EOF (Ctrl+D) was detected. */
	if (message == NULL)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(EXIT_SUCCESS);
	}

	/* Print the error message to stderr. */
	fprintf(stderr, "%s\n", message);

	/* Exit the program with a failure status. */
	exit(EXIT_FAILURE);
}
