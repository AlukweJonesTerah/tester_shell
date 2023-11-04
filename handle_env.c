#include "shell.h"
/**
 * handle_env - Prints the current environment
 */
void handle_env(void)
{
    extern char **environ;
    int i = 0;

    while (environ[i] != NULL)
    {
        custom_printf("%s\n", environ[i]);
        i++;
    }
}