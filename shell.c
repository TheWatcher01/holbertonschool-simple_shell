#include "main.h"
/**
 * main - The entry point of the program
 *
 * Function creates simple shell that reads commands from user and executes it
 * It uses a loop that continues until user enters an EOF character (Ctrl+D).
 * Inside loop, it displays prompt to user, reads command from user,
 * and executes command. If command is NULL (which means that an EOF character
 *  was entered), it exits loop and program ends.
 *
 * Return: 0 if program ends normally, or a non-zero value if an error occurs.
 */
int main(void)
{
	char *command;

	while (1)
	{
		prompt();

		command = read_command();

		execute_command(command);

		free(command);
	}

	return (0);
}
