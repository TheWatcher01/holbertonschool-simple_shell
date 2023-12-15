#include "main.h"
/**
 * get_command_path - Retrieve the full path of a given command.
 * @command: The command to find the full path for.
 *
 * Function searches for given command in directories specified by PATH
 * environment variable. It checks each directory in PATH in order, and returns
 * full path of the first matching command it finds.
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *get_command_path(char *command)
{
	/* Duplicate PATH environment variable to avoid modifying original */
	char *path_copy = strdup(getenv("PATH"));

	/* Split the duplicated PATH into individual directories */
	char *dir = strtok(path_copy, ":");

	/* Allocate memory to hold the full path of the command */
	char *command_path = malloc(1024);

	/* Iterate over each directory in the PATH */
	while (dir != NULL)
	{
		/* Construct the full path of command in current directory */
		sprintf(command_path, "%s/%s", dir, command);

		/* Check if the command is executable in current directory */
		if (access(command_path, X_OK) == 0)
		{
			/* If command is found, clean up and return full path*/
			free(path_copy);
			return (command_path);
		}

		/* Move on to the next directory in the PATH */
		dir = strtok(NULL, ":");
	}

	/*If command was not found in any directory, clean up and return NULL*/
	free(command_path);
	free(path_copy);
	return (NULL);
}
