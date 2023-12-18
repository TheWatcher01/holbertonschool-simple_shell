#include "main.h"

void exit_command(char **argv_exec)
{
	if (strcmp(argv_exec[0], "exit") == 0)
	{
		if (argv_exec[1] != NULL)
		{
			exit(atoi(argv_exec[1]));
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
}
