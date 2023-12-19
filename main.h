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
void print_env(void);
char *get_command_path(char *command);
int builtin_exit(char **argv_exec);
int builtin_env(char **argv_exec);
int execute_builtin_command(char **argv_exec);
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



/** Environment Variables */

extern char **environ;




#endif /* MAIN_H */
