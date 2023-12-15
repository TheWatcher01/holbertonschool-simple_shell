#include "main.h"

char *read_command(char **command, size_t *len)
{
	int read = getline(command, len, stdin);
	if (read == -1 || feof(stdin))
	{
		free(*command);
		return NULL;
	}
	(*command)[strcspn(*command, "\n")] = 0;
	if ((*command)[0] == '\0')
	{
		free(*command);
		*command = NULL;
	}
	return *command;
}
