#include "shell.h"
/**
 * split_input - Splits the input line into a command and its arguments
 * @input: User input
 * @argv: Array to store command and arguments
 * @max_args: Maximum number of arguments
 * Return: Number of arguments
 */
int split_input(char *input, char *argv[], int max_args)
{
    int argc = 0;
    int in_word = 0;  /* Indicates whether we are inside a word */
    int i = 0, j;        /* Index for the current argument */

    for (j = 0; input[j] != '\0'; j++)
    {
        if (input[j] == ' ' || input[j] == '\t' || input[j] == '\n')
        {
            if (in_word)
            {
                argv[argc][i] = '\0';
                argc++;
                in_word = 0;
                i = 0;
            }
        }
        else
        {
            if (!in_word)
            {
                if (argc >= max_args - 1) {
                    /* Prevent exceeding the maximum number of arguments */
                    break;
                }
                argv[argc] = &input[j];
                in_word = 1;
            }
            argv[argc][i] = input[j];
            i++;
        }
    }
    /* Null-terminate the last argument */
    if (in_word)
    {
        argv[argc][i] = '\0';
        argc++;
    }
    argv[argc] = NULL;
    return argc;
}
