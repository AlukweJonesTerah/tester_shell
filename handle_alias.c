#include "shell.h"
/**
 * handle_alias - Handle alias command
 * @args: Array of alias arguments
 */
void handle_alias(char *args[])
{
    int i;

    if (args[1] == NULL)
    {
        /* Print all aliases */
        for (i = 0; i < num_aliases; i++)
        {
            fprintf(stdout, "alias %s='%s'\n", aliases[i].name, aliases[i].value);
        }
    }
    else if (args[2] == NULL)
    {
        /* Print specific alias */
        struct Alias *alias = find_alias(args[1]);
        if (alias)
        {
            fprintf(stdout, "alias %s='%s'\n", alias->name, alias->value);
        }
    }
    else
    {
        /* Define or redefine aliases */
        for (i = 1; args[i] != NULL; i++)
        {
            char *name = strtok(args[i], "=");
            char *value = strtok(NULL, "=");
            if (name && value)
            {
                struct Alias *alias = find_alias(name);
                if (alias)
                {
                    /* Update existing alias */
                    free(alias->value);
                    alias->value = strdup(value);
                }
                else if (num_aliases < MAX_ALIASES)
                {
                    /* Create a new alias */
                    aliases[num_aliases].name = strdup(name);
                    aliases[num_aliases].value = strdup(value);
                    num_aliases++;
                }
                else
                {
                    fprintf(stderr, "Maximum number of aliases reached\n");
                    return;
                }
            }
        }
    }
}
