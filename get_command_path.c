#include "main.h"
/**
 * get_command_path - Retrieve the full path of a given command.
 * @command: The command to find the full path for.
 * Return: The full path of the command if found, NULL otherwise.
 */
char *get_command_path(char *command)
{
	char *path_copy = strdup(getenv("PATH"));
	char *dir, *command_path = NULL;
	char *cached_path = get_from_cache(command);

	if (cached_path)
	{
		free(path_copy);
		return (strdup(cached_path));
	}
	if (!path_copy)
	{
		handle_error("Error: Failed to allocate memory", NULL);
		return (NULL);
	}

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		command_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!command_path)
		{
			handle_error("Error: Failed to allocate memory", path_copy);
			return (NULL);
		}

		sprintf(command_path, "%s/%s", dir, command);

		if (access(command_path, X_OK) == 0)
		{
			add_to_cache(command, command_path);
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		dir = strtok(NULL, ":");
	}
	handle_error("Error: Command not found", path_copy);
	return (NULL);
}
