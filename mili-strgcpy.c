#include "shell.h"

/**
 * _strgcpy - function that copies the string pointed to by source
 * @dest: Pointer to the destination of copied string
 * @src: Pointer to the source of string
 * Return: Pointer to the destination string
 */
char *_strgcpy(char *dest, char *src)
{
        size_t n;

        for (n = 0; src[n] != '\0'; n++)
        {
                dest[n] = src[n];
        }
        dest[n] = '\0';

        return (dest);
}
