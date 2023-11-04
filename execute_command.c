#include "shell.h"
/**
 * execute_command - Executes a single command
 * @command: The command to execute
 * Return: 1 if the command succeeded, 0 if it failed
 */
int execute_command(char *command)
{
     /* Remove comments by searching for a '#' and replacing it with '\0' */
    char *comment_pos = strchr(command, '#');
    char *argv[32];
    int argc, status;
    
    if (comment_pos != NULL) {
        *comment_pos = '\0';
    }

    argc = split_input(command, argv, sizeof(argv) / sizeof(argv[0]));

    if (argc == 0)
        return 1;  /* Success by default for empty commands */

    if (strcmp(argv[0], "exit") == 0)
    {
        if (argc == 1)
            exit(0);
        else if (argc == 2)
            exit(atoi(argv[1]));
        else
            fprintf(stderr, "Usage: exit [status]\n");
    }
    else if (strcmp(argv[0], "env") == 0)
    {
        handle_env();
        return 1;
    }
    else if (strcmp(argv[0], "setenv") == 0)
    {
        handle_setenv(argv);
        return 1;
    }
    else if (strcmp(argv[0], "unsetenv") == 0)
    {
        handle_unsetenv(argv);
        return 1;
    }
    else if (strcmp(argv[0], "cd") == 0)
    {
        handle_cd(argv);
        return 1;
    }
    else if (find_command(argv[0], getenv("PATH"), command))
    {
        if (fork() == 0)
        {
            if (execve(command, argv, NULL) == -1)
            {
                perror("Error");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
            return WIFEXITED(status) && WEXITSTATUS(status) == 0;
        }
    }
    else
    {
        fprintf(stderr, "Command not found: %s\n", argv[0]);
        return 0;
    }

    /* expand_variables(command); */
    /* return execute_alias(command); */
    return 0;  /* Return 0 for failed commands by default */
}
