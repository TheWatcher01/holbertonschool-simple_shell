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

/** Function Prototypes */

void prompt(void);
char *read_command(char **command, size_t *len);
void execute_command(char **argv_exec);
char **parse_command(char *command);
char *get_command_path(char *command);
void print_env(void);
/* void exit_shell(char **argv_exec); */

/** Structure Prototypes */


/** Environment Variables */

extern char **environ;




#endif /* MAIN_H */
