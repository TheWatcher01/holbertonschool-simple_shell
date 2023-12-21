#include "main.h"

/**
 * builtin_exit - Exit the shell
 * @argv_exec: Null-terminated array of arguments
 *
 * Return: Does not return because the function exits the shell
 */
int builtin_exit(char **argv_exec)
{
	(void)argv_exec;
	exit(0);
}

/**
 * builtin_env - Print the environment
 * @argv_exec: Null-terminated array of arguments
 *
 * Return: 0 on success
 */
int builtin_env(char **argv_exec)
{
	(void)argv_exec;
	print_env();
	return (0);
}

/**
 * execute_builtin_command - Execute a builtin command
 * @argv_exec: Null-terminated array of arguments
 *
 * Return: 0 on success, or -1 if the command is not a builtin command
 */
int execute_builtin_command(char **argv_exec)
{
	builtin_command_t builtin_commands[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
		{NULL, NULL}
	};

	int i;

	for (i = 0; builtin_commands[i].name != NULL; i++)
	{
		if (strcmp(argv_exec[0], builtin_commands[i].name) == 0)
		{
			return (builtin_commands[i].func(argv_exec));
		}
	}

	return (-1);
}
