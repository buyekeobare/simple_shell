#include "shell.h"

/**
 * check_envir_var - Function that checks if the typed 
 * variable is an environment variable
 * @hd: The head of linked list
 * @n: input string
 * @data_sh: relevant data strcuture
 */
void check_envir_var(rVar **hd, char *n, data_shell *data_sh)
{
	int rw, ch, a, vallen;
	char **envr;

	envr = data_sh->envir;
	for (rw = 0; envr[row]; rw++)
	{
		for (a = 1, ch = 0; envr[rw][]; ch++)
		{
			if (envr[rw][chr] == '=')
			{
				vallen = _strglen(envr[rw] + ch + 1);
				add_var_end(h, a, envr[rw] + ch + 1, lval);
				return;
			}

			if (n[a] == envr[rw][ch])
				a++;
			else
				break;
		}
	}

	for (a = 0; n[a]; a++)
	{
		if (n[a] == ' ' || n[a] == '\t' || n[a] == ';' || n[a] == '\n')
			break;
	}

	add_var_end(hd, a, NULL, 0);
}

/**
 * check_variables - Function that checks if 
 * the typed variable is $$ or $?
 * @hd: head of the linked list
 * @n: input string
 * @last_stat: last status of the Shell
 * @data_sh: relevant data structure 
 */
int check_variables(r_Var **hd, char *n, char *last_stat, data_shell *data_sh)
{
	int k, last_status_len, pid_len;

	last_status_len = _strglen(last_stat);
	pid_len = _strglen(data_sh->pid);

	for (k = 0; n[k]; k++)
	{
		if (n[k] == '$')
		{
			if (n[k + 1] == '?')
				add_var_end(hd, 2, last_stat, last_status_len), k++;
			else if (n[k + 1] == '$')
				add_var_end(hd, 2, data_sh->pid, pid_len), k++;
			else if (n[k + 1] == '\n')
				add_var_end(hd, 0, NULL, 0);
			else if (n[k + 1] == '\0')
			add_var_end(hd, 0, NULL, 0);
			else if (n[k + 1] == ' ')
			add_var_end(hd, 0, NULL, 0);
			else if (n[k + 1] == '\t')
				add_var_end(hd, 0, NULL, 0);
			else if (n[k + 1] == ';')
				add_var_end(hd, 0, NULL, 0);
			else
				check_envir_var(hd, n + k, data_sh);
		}
	}

	return (k);
}

/**
 * rep_input - A function that replaces 
 * a string into variables
 * @hd: Head of the linked list.
 * @n: input string.
 * @new_inp: new input string (replaced)
 * @new_len: new length.
 * Return: Replaced string
 */
char *rep_input(rVar **hd, char *n, char *new_inp, int new_len)
{
	rVar *indx;
	int l, m, p;

	indx = *hd;
	for (m = l = 0; l < new_len; l++)
	{
		if (n[m] == '$')
		{
			if (!(indx->var_length) && !(indx->val_length))
			{
				new_inp[i] = n[m];
				m++;
			}
			else if (indx->var_length && !(indx->val_length))
			{
				for (p = 0; p < indx->var_length; p++)
					m++;
				l--;
			}
			else
			{
				for (p = 0; p < indx->val_length; p++)
				{
					new_input[m] = indx->var_value[p];
				l++;
				}
				m += (indx->var_length);
				l--;
			}
			indx = indx->nxtNode;
		}
		else
		{
			new_inp[l] = n[m];
			m++;
		}
	}

	return (new_inpt);
}

/**
 * rep_variables - A function that replaces 
 * string into variables
 * @n: input string
 * @data_sh: (structure) relevant data
 * Return: Replaced string.
 */
char *rep_variables(char *n, data_shell *data_sh)
{
	rVar *hd, *indx;
	char *stat, *new_Input;
	int old_len, new_len;

	stat = mili_itoa(data_sh->stat);
	hd = NULL;

	old_len = check_variables(&hd, n, stat, data_sh);

	if (hd == NULL)
	{
		free(stat);
		return (n);
	}

	indx = hd;
	new_len = 0;

	while (indx != NULL)
	{
		new_len += (indx->val_length - indx->var_length);
		indx = indx->nxtNode;
	}

	new_len += old_len;

	new_input = malloc(sizeof(char) * (new_len + 1));
	new_input[new_len] = '\0';

	new_input = rep_input(&hd, n, new_input, new_len);

	free(n);
	free(stat);
	free_var_list(&hd);

	return (new_input);
}