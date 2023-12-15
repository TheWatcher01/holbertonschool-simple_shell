#include "main.h"
/**
 * main - The entry point of the program
 * @argc: The number of command-line arguments
 * @argv: The command-line arguments
 *
 * Function creates simple shell that reads commands from user and executes it
 * It uses a loop that continues until user enters an EOF character (Ctrl+D).
 * Inside loop, it displays prompt to user, reads command from user,
 * and executes command. If command is NULL (which means that an EOF character
 *  was entered), it exits loop and program ends.
 *
 * Return: 0 if program ends normally, or a non-zero value if an error occurs.
 */
int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t len = 0;

	(void)argc;
	(void)argv;

	/*Start loop that continues until user enters EOF character (Ctrl+D)*/
	while (1)
	{
		prompt();

		if (read_command(&command, &len) == NULL)
			/*If command is NULL, exit loop and end program*/
			return (0);

		execute_command(command);

		free(command);

		/* Set the command string to NULL for the next iteration */
		command = NULL;
	}
	return (0);
}
