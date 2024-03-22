#include "shell.h"

/**
 * _strgchr - A function that locates a character in a string
 * @s: strg to be searched
 * @c: char to be located
 * Return: pointer to the first occurrence of c character
 * or NULL if no character is found
 */
char *_strgchr(char *s, char c)
{
        unsigned int n = 0;

        for (; *(s + n) != '\0'; n++)
                if (*(s + n) == c)
                        return (s + n);
        if (*(s + n) == c)
                return (s + n);
        return ('\0');
}
