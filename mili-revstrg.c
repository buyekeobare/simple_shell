#include "shell.h"

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
