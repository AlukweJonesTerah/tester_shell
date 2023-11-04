#include "shell.h"
/**
 * handle_unsetenv - Removes an environment variable
 * @args: Array containing command and arguments
 */
void handle_unsetenv(char *args[])
{
    if (args[1] != NULL)
    {
        if (unsetenv(args[1]) != 0)
            fprintf(stderr, "Failed to unset environment variable.\n");
    }
    else
    {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
    }
}