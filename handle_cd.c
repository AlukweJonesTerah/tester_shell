#include "shell.h"
/**
 * handle_cd - Changes the current directory of the process and updates PWD
 * @args: Array containing command and arguments
 */
void handle_cd(char *args[])
{
    char *new_dir;
    char *current_dir = getcwd(NULL, 0);

    if (args[1] == NULL || strcmp(args[1], "~") == 0)
        new_dir = getenv("HOME");
    else if (strcmp(args[1], "-") == 0)
        new_dir = getenv("OLDPWD");
    else
        new_dir = args[1];

    if (chdir(new_dir) == 0)
    {
        setenv("OLDPWD", current_dir, 1);
        setenv("PWD", getcwd(NULL, 0), 1);
        free(current_dir);
    }
    else
    {
        perror("Error");
        free(current_dir);
    }
}