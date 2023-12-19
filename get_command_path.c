#include "main.h"

/**
 * get_command_path - Retrieve the full path of a given command.
 * @command: The command to find the full path for.
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *get_command_path(char *command)
{
	char *path_copy = strdup(getenv("PATH"));
	char *dir = strtok(path_copy, ":");
	char *command_path = NULL;

	while (dir != NULL)
	{
		command_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!command_path)
		{
			free(path_copy);
			return (NULL);
		}

		sprintf(command_path, "%s/%s", dir, command);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}

		free(command_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
