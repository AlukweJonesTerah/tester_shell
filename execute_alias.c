#include "shell.h"
/**
 * execute_alias - Execute a command with alias substitution
 * @command: The command to execute
 * Return: 1 if the command succeeded, 0 if it failed
 */
int execute_alias(char *command) {
    char *argv[32];
    int argc, status;

    argc = split_input(command, argv, sizeof(argv) / sizeof(argv[0]));

    if (argc == 0)
        return 1;  /* Success by default for empty commands */

    if (strcmp(argv[0], "exit") == 0) {
        if (argc == 1)
            exit(0);
        else if (argc == 2)
            exit(atoi(argv[1]));
        else
            custom_printf("Usage: exit [status]\n");
    } else if (strcmp(argv[0], "env") == 0) {
        handle_env();
        return 1;
    } else if (strcmp(argv[0], "setenv") == 0) {
        handle_setenv(argv);
        return 1;
    } else if (strcmp(argv[0], "unsetenv") == 0) {
        handle_unsetenv(argv);
        return 1;
    } else if (strcmp(argv[0], "cd") == 0) {
        handle_cd(argv);
        return 1;
    } else if (find_alias(argv[0])) {
        /* Substitute alias value and execute */
        char alias_command[MAX_INPUT];
        int alias_command_length = 0, i;

        for (i = 0; i < argc; i++) {
            alias_command_length += strlen(argv[i]) + 1; /* +1 for space */
        }

        if (alias_command_length < MAX_INPUT) {
            custom_strcpy(alias_command, find_alias(argv[0])->value);

            for (i = 1; i < argc; i++) {
                custom_strcat(alias_command, " ");
                custom_strcat(alias_command, argv[i]);
            }

            return execute_alias(alias_command);
        } else {
            custom_printf("Alias command is too long\n");
            return 0;
        }
    } else if (find_command(argv[0], getenv("PATH"), command)) {
        if (fork() == 0) {
            if (execve(command, argv, NULL) == -1) {
                perror("Error");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(&status);
            return WIFEXITED(status) && WEXITSTATUS(status) == 0;
        }
    } else {
        write(STDERR_FILENO, "Command not found: ", 20);
        write(STDERR_FILENO, argv[0], strlen(argv[0]));
        write(STDERR_FILENO, "\n", 1);
        return 0;
    }
    return 0;  /* Return 0 for failed commands by default */
}
