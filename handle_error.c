#include "main.h"

/**
 * handle_error - Handles errors by printing error message and exiting program
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

	/* Print the error message to stderr. */
	fprintf(stderr, "%s\n", message);

	/* Exit the program with a failure status. */
	exit(EXIT_FAILURE);
}
