#include "shell.h"

/**
 * comment_remove - Function that deletes comments from the input
 * @n: input string
 * Return: input without comments
 */
char *comment_remove(char *n)
{
        int k, upto;

        upto = 0;
        for (k = 0; n[k]; k++)
        {
                if (n[k] == '#')
                {
                        if (k == 0)
                        {
                                free(n);
                                return (NULL);
                        }

                        if (n[k - 1] == ' ' || n[k - 1] == '\t' || n[k - 1] == ';')
                                upto = k;
                }
        }

        if (upto != 0)
        {
                n = mili_realloc(n, k, upto + 1);
                n[upto] = '\0';
        }

        return (n);
}

/**
 * _shellloop - a function that is a Loop of shell
 * @data_sh: relevant data structure(argv, input, args)
 * Return: no return
 */
void _shellloop(data_shell *data_sh)
{
        int loop, l_eof;
        char *n;

        loop = 1;
        while (loop == 1)
        {
                write(STDIN_FILENO, "^-^ ", 4);
                n = read_input(&l_eof);
                if (l_eof != -1)
                {
                        n = comment_remove(n);
                        if (n == NULL)
                                continue;

                        if (finds_prints_syntax_error(data_sh, n) == 1)
                        {
                                data_sh->stat = 2;
                                free(n);
                                continue;
                        }
                        n = rep_variables(n, data_sh);
                        loop = split_cmds(data_sh, n);
                        data_sh->result += 1;
                        free(n);
                }
                else
                {
                        loop = 0;
                        free(n);
                }
        }
}
