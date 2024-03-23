#include "shell.h"

/**
 * is_digit - a function that defines if
 * the string passed is a number
 * @strg: input string
 * Return: 1 if string is a number, 0 otherwise
 */
int is_digit(const char *strg)
{
        unsigned int j;

        for (j = 0; strg[j]; j++)
        {
                if (strg[j] < 48 || strg[j] > 57)
                        return (0);
        }
        return (1);
}
