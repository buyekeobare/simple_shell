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
                if (_cmpChars(strg, delim))
                        return (NULL);
                s_splitted = strg; /*Store 1st address*/
                j = _strglen(strg);
                strgEnd = &strg[j]; /*store last address*/
        }
        strgStart = s_splitted;
        if (strgStart == strgEnd) /* reaching the end */
                return (NULL);

        for (bool = 0; *s_splitted; s_splitted++)
        {
                /* breaking loop, finding the next token */
                if (s_splitted != strgStart)
                        if (*s_splitted && *(s_splitted - 1) == '\0')
                                break;
                /* replacing delimiter for null characters */
                for (j = 0; delim[j]; j++)
                {
                        if (*s_splitted == delim[j])
                        {
                                *s_splitted = '\0';

                                if (s_splitted == strgStart)
                                        strgStart++;
                                break;
                        }
                }
                if (bool == 0 && *s_splitted) /* strg not equal to delim */
                        bool = 1;
        }
        if (bool == 0) /*strg equal to delim*/
                return (NULL);
        return (strgStart);
}

