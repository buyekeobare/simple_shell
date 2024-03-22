#include "shell.h"

/**
 * _strgcmp - function that compares two strings
 * @s1: fisrt strg to be compared
 * @s2: second strg to be compared
 * Return: Always 0
 */
int _strgcmp(char *s1, char *s2)
{
        int j;

        for (j = 0; s1[j] == s2[j] && s1[j]; j++)
                ;

        if (s1[j] > s2[j])
                return (1);
        if (s1[j] < s2[j])
                return (-1);
        return (0);
}
