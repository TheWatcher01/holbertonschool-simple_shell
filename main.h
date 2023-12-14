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

char **split_string(char *str);



/** Structure Prototypes */


/** Environment Variables */

extern char **environ;




#endif /* MAIN_H */
