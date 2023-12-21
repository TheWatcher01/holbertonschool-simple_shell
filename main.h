#ifndef MAIN_H
#define MAIN_H

/** Library Included */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/** Function Prototypes */

void prompt(void);

char *read_command(char **command, size_t *len);
int execute_command(char **argv_exec);
char **parse_command(char *command);
char *get_command_path(char *command);

void print_env(void);

int builtin_exit(char **argv_exec);
int builtin_env(char **argv_exec);
int execute_builtin_command(char **argv_exec);

void handle_error(char *message, char *mem_to_free);

void sigint_handler(int sig);
void set_sigint_handler(void);

char *get_from_cache(char *command);
void *add_to_cache(char *command, char *path);
void free_command_cache(void);

/** Structure Prototypes */

/**
 * struct builtin_command - Structure for builtin commands
 * @name: Name of the builtin command
 * @func: Function to execute the builtin command
 */
typedef struct builtin_command
{
	char *name;
	int (*func)(char **argv_exec);
} builtin_command_t;

/**
 * struct command_cache - Structure for caching command paths
 * @command: Name of the command
 * @path: Path to the command
 * @next: Pointer to the next item in the linked list of command path caches
 */
typedef struct command_cache
{
	char *command;
	char *path;
	struct command_cache *next;
} command_cache_t;

/** Environment Variables */

extern char **environ;

#endif /* MAIN_H */
