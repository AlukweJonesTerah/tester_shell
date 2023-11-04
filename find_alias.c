#include "shell.h"
/**
 * find_alias - Find an alias by name
 * @name: Alias name
 * Return: Pointer to the alias, or NULL if not found
 */
struct Alias *find_alias(const char *name)
{
    int i;
    for (i = 0; i < num_aliases; i++)
    {
        if (strcmp(aliases[i].name, name) == 0)
            return &aliases[i];
    }
    return NULL;
}