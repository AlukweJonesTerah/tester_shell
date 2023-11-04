#include "shell.h"
/**
 * handle_setenv - Sets a new environment variable or modifies an existing one
 * @args: Array containing command and arguments
 */
void handle_setenv(char *args[])
{
    if (args[1] != NULL && args[2] != NULL)
    {
        if (setenv(args[1], args[2], 1) != 0)
            fprintf(stderr, "Failed to set environment variable.\n");
    }
    else
    {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
    }
}