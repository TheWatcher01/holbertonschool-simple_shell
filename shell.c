#include "main.h"

int main(int argc, char *argv[])
{
	char *command = NULL;
	size_t len = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		prompt();
		if (read_command(&command, &len) == NULL)
			return (0);
		execute_command(command);
		free(command);
		command = NULL;
	}
	return (0);
}
