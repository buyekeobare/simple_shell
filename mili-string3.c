#include "shell.h"

/**
 * _cmpChars - Function that compares characters of string
 * @strg: input string to compare
 * @delim: delimiter string to compare
 * Return: 1 or 0 otherwise
 */
int _cmpChars(char strg[], const char *delim)
{
	unsigned int m, n, p;

	for (m = 0, p = 0; strg[m]; m++)
	{
		for (n = 0; delim[n]; n++)
		{
			if (strg[m] == delim[n])
			{
				p++;
				break;
			}
		}
	}
	if (m == p)
		return (1);
	return (0);
}

/**
 * _strgtok - Function that splits a string 
 * by some delimiter
 * @strg: string to be splitted
 * @delim: delimiter string
 * Return: splitted string
 */
char *_strgtok(char strg[], const char *delim)
{
	static char *s_splitted, *strgEnd;
	char *strgStart;
	unsigned int j, bool;

	if (strg != NULL)
	{
		if (cmpChars(strg, delim))
			return (NULL);
		s_splitted = strg; /*Store 1st address*/
		j = _strglen(strg);
		strEnd = &strg[j]; /*store last address*/
	}
	strStart = s_splitted;
	if (strStart == strEnd) /* reaching the end */
		return (NULL);

	for (bool = 0; *s_splitted; s_splitted++)
	{
		/* breaking loop, finding the next token */
		if (s_splitted != strStart)
			if (*s_splitted && *(s_splitted - 1) == '\0')
				break;
		/* replacing delimiter for null characters */
		for (j = 0; delim[j]; j++)
		{
			if (*s_splitted == delim[j])
			{
				*s_splitted = '\0';

				if (s_splitted == strStart)
					strStart++;
				break;
			}
		}
		if (bool == 0 && *s_splitted) /* strg not equal to delim */
			bool = 1;
	}
	if (bool == 0) /*strg equal to delim*/
		return (NULL);
	return (strStart);
}

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
