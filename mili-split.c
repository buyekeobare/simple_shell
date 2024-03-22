#include "shell.h"

/**
 * swap_characters - A function that swaps | and & for non-printed chars
 * @n: input string
 * @shld_swap: a type of swap.
 * Return: swapped string
 */
char *swap_characters(char *n, int shld_swap)
{
	int j;

	if (shld_swap == 0)
	{
		for (j = 0; n[j]; j++)
		{
			if (n[j] == '|')
			{
				if (n[j + 1] != '|')
					n[j] = 16;
				else
					j++;
			}

			if (n[j] == '&')
			{
				if (n[j + 1] != '&')
					n[j] = 12;
				else
					j++;
			}
		}
	}
	else
	{
		for (j = 0; n[j]; j++)
		{
			n[j] = (n[j] == 16 ? '|' : n[j]);
			n[j] = (n[j] == 12 ? '&' : n[j]);
		}
	}
	return (n);
}

/**
 * add_sep_commands - To add separators and command lines in the lists
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @n: input string
 */
void add_sep_commands(separ_list **head_s, line_lst **head_l, char *n)
{
	int j;
	char *lines;

	n = swap_characters(n, 0);

	for (j = 0; n[j]; j++)
	{
		if (n[j] == ';')
			add_separ_list_end(head_s, n[j]);

		if (n[j] == '|' || n[j] == '&')
		{
			add_separ_list_end(head_s, n[j]);
			j++;
		}
	}

	lines = _strgtok(n, ";|&");
	do {
		lines = swap_characters(lines, 1);
		add_line_list_end (head_l, lines);
		lines = _strgtok(NULL, ";|&");
	} while (lines != NULL);

}

/**
 * next_cmd_line - Function that goes to the next command line stored
 * @list_s: separator list
 * @list_l: command line list
 * @data_sh: data structure
 * Return: no return
 */
void next_cmd_line(separ_list **list_s, line_lst **list_l, data_shell *data_sh)
{
	int sep_loop;
	separ_list *ls_s;
	line_lst *ls_l;

	sep_loop = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && sep_loop)
	{
		if (data_sh->stat == 0)
		{
			if (ls_s->m_separator== '&' || ls_s->m_separator == ';')
				sep_loop = 0;
			if (ls_s->m_separator == '|')
				ls_l = ls_l->nextNode, ls_s = ls_s->nextNode;
		}
		else
		{
			if (ls_s->m_separator == '|' || ls_s->m_separator == ';')
				sep_loop = 0;
			if (ls_s->m_separator == '&')
				ls_l = ls_l->nextNode, ls_s = ls_s->nextNode;
		}
		if (ls_s != NULL && !sep_loop)
			ls_s = ls_s->nextNode;
	}

  	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_cmds - A function that splits command lines according to
 * m_separators ;, | and &, and executes them
 * @data_sh: (data structure) relevant data
 * @n: input string
 * Return: 0 to exit, 1 to continue
 */
int split_cmds(data_shell *data_sh, char *n)
{

	separ_list *head_s, *list_s;
	line_lst *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_sep_commands(&head_s, &head_l, n);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		data_sh->n = list_l->line_cmd;
		data_sh->args = split_string(data_sh->n);
		loop = _execline(data_sh);
		free(data_sh->args);

		if (loop == 0)
			break;

		next_cmd_line(&list_s, &list_l, data_sh);

		if (list_l != NULL)
			list_l = list_l->nextNode;
	}

	free_separ_list(&head_s);
	free_line_lst(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_string - a function that tokenizes the input string
 * @n: input string.
 * Return: string splitted.
 */
char **split_string(char *n)
{
	size_t buffer_size;
	size_t index;
	char **tokens;
	char *curt_token;

	buffer_size = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (buffer_size));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	curt_token = _strgtok(n, TOK_DELIM);
	tokens[0] = curt_token;

	for (index = 1; curt_token != NULL; index++)
	{
		if (index == buffer_size)
		{
			buffer_size += TOK_BUFSIZE;
			tokens = mili_realloc_dp(tokens, index, sizeof(char *) * buffer_size);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		curt_token = _strgtok(NULL, TOK_DELIM);
		tokens[index] = curt_token;
	}

	return (tokens);
}
