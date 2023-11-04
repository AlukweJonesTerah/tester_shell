#include "shell.h"
/**
 * expand_variables - Expand variables in the command
 * @command: The command to expand variables in
 */
void expand_variables(char *command)
{
    char expanded_command[MAX_INPUT];
    char *token;
    char *rest = command;
    size_t index = 0;
    int pid = getpid();

    while ((token = strtok_r(rest, " ", &rest)))
    {
        if (strcmp(token, "$?") == 0)
        {
            sprintf(expanded_command + index, "%d", last_command == NULL ? 1 : 0);
            index += strlen(expanded_command + index);
        }
        else if (strcmp(token, "$$") == 0)
        {
            sprintf(expanded_command + index, "%d", pid);
            index += strlen(expanded_command + index);
        }
        else
        {
            sprintf(expanded_command + index, "%s", token);
            index += strlen(expanded_command + index);
        }

        expanded_command[index++] = ' ';
    }

    expanded_command[index] = '\0';
    strcpy(command, expanded_command);
}