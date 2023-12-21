#include "main.h"

static command_cache_t *command_cache_head;

/**
 * add_to_cache - Add a command to the cache
 * @command: The command to add
 * @path: The path of the command
 *
 * Return: Pointer to the new node, or NULL on failure
 */

void *add_to_cache(char *command, char *path)
{
	command_cache_t *new_node = malloc(sizeof(command_cache_t));

	if (!new_node)
	{
		handle_error("Error: Failed to allocate memory", NULL);
		return (NULL);
	}

	new_node->command = strdup(command);
	new_node->path = strdup(path);
	new_node->next = command_cache_head;
	command_cache_head = new_node;

	return (new_node);
}

/**
 * get_from_cache - Retrieve a command from the cache
 * @command: The command to retrieve
 *
 * Return: The path of the command, or NULL if the command is not in the cache
 */

char *get_from_cache(char *command)
{
	command_cache_t *node = command_cache_head;

	while (node)
	{
		if (strcmp(node->command, command) == 0)
		{
			return (node->path);
		}
		node = node->next;
	}

	return (NULL);
}

/**
 * free_command_cache - Free all nodes in the command cache
 */

void free_command_cache(void)
{
	command_cache_t *current_node = command_cache_head;
	command_cache_t *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node->command);
		free(current_node->path);
		free(current_node);
		current_node = next_node;
	}

	command_cache_head = NULL;
}
