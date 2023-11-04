#include "shell.h"
/**
 * commands_separator - Splits the input line into multiple commands
 * @input: User input
 * @commands: Array to store individual commands
 * @max_commands: Maximum number of commands
 * Return: Number of commands
 */
int commands_separator(char *input, char *commands[], int max_commands)
{
    int num_commands = 0;
    char *token;

    token = strtok(input, ";");
    while (token != NULL && num_commands < max_commands)
    {
        commands[num_commands] = token;
        num_commands++;
        token = strtok(NULL, ";");
    }

    return num_commands;
}