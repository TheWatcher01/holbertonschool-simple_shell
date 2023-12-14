#include "main.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description: This program prints the number of arguments it receives,
 * and then prints each argument with its corresponding index.
 *
 * Return: Always 0 (Success)
 */

int main(int ac, char **av)
{
	/* Print the number of arguments */
	printf("Nombre d'arguments : %d\n", ac);

	/* Loop through each argument in the argument vector */
	for (int i = 0; i < ac; i++)
	{
		/* Print the current argument with its index */
		printf("Arguments %d : %s\n", i + 1, av[i]);
	}

	/* Return 0 to indicate successful execution */
	return (0);
}
