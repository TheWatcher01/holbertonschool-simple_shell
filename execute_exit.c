#include "main.h"

void execute_exit(char **argv_exec)
{
    int exit_status = 0;

    if (argv_exec[1])
    {
        exit_status = atoi(argv_exec[1]);
    }

    exit(exit_status);
}
