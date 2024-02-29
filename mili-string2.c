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

/**
 * revStrg - a function that reverses a string
 * @strg: input string
 */
void revStrg(char *strg)
{
	int count = 0, k, d;
	char *s, tmp;

	while (count >= 0)
	{
		if (strg[count] == '\0')
			break;
		count++;
	}
	s = strg;

	for (k = 0; k < (count - 1); k++)
	{
		for (d = k + 1; d > 0; d--)
		{
			tmp = *(s + d);
			*(s + d) = *(s + (d - 1));
			*(s + (d - 1)) = tmp;
		}
	}
}