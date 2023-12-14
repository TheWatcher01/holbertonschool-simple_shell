#include "main.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description: This program prints all the arguments it receives,
 * one argument per line. The argument count is ignored.
 *
 * Return: Always 0 (Success)
 */

int main(int ac, char **av)
{
	(void)ac; /* Ignore argument count */

	/* Loop through each argument in the argument vector */
	while (*av)
	{
		/* Print the current argument */
		printf("%s\n", *av);

		/* Move to the next argument */
		av++;
	}

	/* Return 0 to indicate successful execution */
	return (0);
}
