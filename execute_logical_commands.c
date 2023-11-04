#include "shell.h"
/**
 * execute_logical_commands - Executes multiple commands with logical operators
 * @commands: Array of commands
 * @num_commands: Number of commands
 * @logical_operator: Logical operator ("&&" or "||")
 */
void execute_logical_commands(char *commands[], int num_commands, const char *logical_operator)
{
    int success = 1, i;

    for (i = 0; i < num_commands; i++)
    {
        if (strcmp(logical_operator, "&&") == 0)
        {
            if (success)
                success = execute_command(commands[i]);
        }
        else if (strcmp(logical_operator, "||") == 0)
        {
            if (!success)
                success = execute_command(commands[i]);
        }
    }
}
