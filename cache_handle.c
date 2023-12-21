#include "main.h"

static command_cache_t *command_cache_head = NULL;

void *add_to_cache(char *command, char *path)
{
	command_cache_t *new_node = malloc(sizeof(command_cache_t));
	if (!new_node)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}

	new_node->command = strdup(command);
	new_node->path = strdup(path);
	new_node->next = command_cache_head;
	command_cache_head = new_node;

	return (new_node);
}

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

char *check_cache(char *command) {
	char *cached_path = get_from_cache(command);
	if (cached_path) {
		return (strdup(cached_path));
	}
	return (NULL);
}

void free_command_cache()
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
