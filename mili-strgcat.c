#include "shell.h"

/**
 * _strgcat - function that concatenates two strings
 * @dest: Pointer to the destination of copied string
 * @src: Pointer to the source of string
 * Return: Pointer to the destination string
 */
char *_strgcat(char *dest, const char *src)
{
        int a, b;

        for (a = 0; dest[a] != '\0'; a++)
                ;

        for (b = 0; src[b] != '\0'; b++)
        {
                dest[a] = src[b];
                a++;
        }

        dest[a] = '\0';
        return (dest);
}
