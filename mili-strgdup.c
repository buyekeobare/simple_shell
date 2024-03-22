#include "shell.h"

/**
 * _strgdup - function that duplicates a string
 * in a heap memory
 * @strg: the string to duplicate
 * Return: ptr to duplicated string if successfu, NULL otherwise
 */
char *_strgdup(const char *strg)
{
        char *new_strg;
        size_t length = 0;

        if (!strg)
                return (NULL);
        while (strg[length])
                length++;
        new_strg = malloc(sizeof(char) * (length + 1));

        if (!new_strg)
                return (NULL);
        length = 0;
        while (strg[length])
        {
                new_strg[length] = strg[length];
                length++;
        }
        new_strg[length] = '\0';
        return (new_strg);
}
