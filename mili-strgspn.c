#include "shell.h"

/**
 * _strgspn - function that gets the length of a
 * prefix substring
 * @s: the strg to be searched
 * @accept: the premix to be measured
 * Return: number of accepted bytes in the string
 */
int _strgspn(char *s, char *accept)
{
    int nbytes, m, bool;

    for (nbytes = 0; *(s + nbytes) != '\0'; nbytes++)
    {
        bool = 1;
        for (m = 0; *(accept + m) != '\0'; m++)
        {
            if (*(s + nbytes) == *(accept + m))
            {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
            break;
    }
    return (nbytes);
}
