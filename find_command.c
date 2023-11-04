#include "shell.h"
/**
 * find_command - Searches for a command in the PATH
 * @command: The command to search for
 * @path: The PATH environment variable
 * @full_path: The full path of the found command
 * Return: 1 if found, 0 if not found
 */
int find_command(const char *command, const char *path, char *full_path)
{
    char *token, *path_copy, *dir;

    path_copy = strdup(path);
    if (path_copy == NULL)
        return 0;

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        dir = strdup(token);
        if (dir == NULL)
            return 0;

        snprintf(full_path, MAX_INPUT, "%s/%s", dir, command);
        if (is_executable(full_path))
        {
            free(path_copy);
            free(dir);
            return 1;
        }

        free(dir);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return 0;
}