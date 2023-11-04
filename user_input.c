#include "shell.h"
/**
 * execute_interactive_mode - Handle the interactive mode of the shell
 */
void execute_interactive_mode() {
    char input[MAX_INPUT];
    char *commands[32];
    int num_commands;

    while (1) {
        custom_prompt();  /* Display the custom prompt */

        if (fgets(input, MAX_INPUT, stdin) == NULL)
            break;

        num_commands = split_input(input, commands, sizeof(commands) / sizeof(commands[0]));

        if (num_commands > 0) {
            /* Check if the command is an alias command */
            char *alias_args[32];
            int alias_args_count = split_input(commands[0], alias_args, sizeof(alias_args) / sizeof(alias_args[0]));

            if (alias_args_count > 0 && strcmp(alias_args[0], "alias") == 0) {
                handle_alias(alias_args);
                continue;
            }

            if (num_commands > 0) {
                /* Execute the last command */
                int last_command_index = num_commands - 1;
                if (strstr(commands[last_command_index], "&&")) {
                    /* Handle logical operators like '&&' */
                    char *logical_commands[32];
                    int num_logical_commands = split_input(commands[last_command_index], logical_commands, sizeof(logical_commands) / sizeof(logical_commands[0]));
                    if (num_logical_commands > 1) {
                        execute_logical_commands(logical_commands, num_logical_commands, "&&");
                        continue;
                    }
                } else if (strstr(commands[last_command_index], "||")) {
                    /* Handle logical operators like '||'*/
                    char *logical_commands[32];
                    int num_logical_commands = split_input(commands[last_command_index], logical_commands, sizeof(logical_commands) / sizeof(logical_commands[0]));
                    if (num_logical_commands > 1) {
                        execute_logical_commands(logical_commands, num_logical_commands, "||");
                        continue;
                    }
                }

                /*Execute the last command in the array */
                execute_command(commands[last_command_index]);
            }
        }
    }
}
