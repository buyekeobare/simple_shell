#include "shell.h"

/**
 * witht_comment - Function that deletes comments from the input
 * @n: input string
 * Return: input without comments
 */
char *witht_comment(char *n)
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
		n = re_allocate(n, k, upto + 1);
		n[upto] = '\0';
	}

	return (n);
}

/**
 * _shellloop - a function that is a Loop of shell
 * @data_sh: (argv, input, args) relevant  data
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
			inp = wtht_comment(n);
			if (n == NULL)
				continue;

			if (chck_syntax_err (data_sh, n) == 1)
			{
				data_sh->stat = 2;
				free(n);
				continue;
			}
			n = rep_variables(n, data_sh);
			loop = splitCommands(data_sh, n);
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