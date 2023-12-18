#include "main.h"

void exit_shell(char **argv_exec)
{
    /* Free any allocated resources */
    free(argv_exec);

    /* Terminate the shell */
    exit(0);
}
