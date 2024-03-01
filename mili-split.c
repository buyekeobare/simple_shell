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
 * @sep_head: head of separator list
 * @cmd_head: head of command lines list
 * @n: input string
 */
void add_sep_commands(separ_list **sep_head, line_lst **cmd_head, char *n)
{
	int j;
	char *lines;

	n = swap_characters(n, 0);

	for (j = 0; n[j]; j++)
	{
		if (n[j] == ';')
			add_separ_list_end(sep_head, n[j]);

		if (n[j] == '|' || n[j] == '&')
		{
			add_separ_list_end(sep_head, n[j]);
			j++;
		}
	}

	lines = _strgtok(n, ";|&");
	do {
		lines = swap_characters(lines, 1);
		add_line_list_end (cmd_head, lines);
		lines = _strgtok(NULL, ";|&");
	} while (lines != NULL);

}

/**
 * nxt_cmd_line - Function that goes to the next command line stored
 * @sep_list: separator list
 * @cmd_list: command line list
 * @datash: data structure
 * Return: no return
 */
void nxt_cmd_line(separ_list **sep_list, line_lst **cmd_list, data_shell *data_sh)
{
	int sep_loop;
	separ_list *sep_ls;
	line_lst *cmd_ls;

	sep_loop = 1;
	sep_ls = *sep_list;
	cmd_ls = *cmd_list;

	while (sep_ls != NULL && sep_loop)
	{
		if (data_sh->stat == 0)
		{
			if (sep_ls->separator== '&' || sep_ls->separator == ';')
				sep_loop = 0;
			if (sep_ls->separator == '|')
				cmd_ls = cmd_ls->nextNode, sep_ls = sep_ls->nextNode;
		}
		else
		{
			if (sep_ls->separator == '|' || sep_ls->separator == ';')
				sep_loop = 0;
			if (sep_ls->septor == '&')
				cmd_ls = cmd_ls->nextNode, sep_ls = sep_ls->nextNode;
		}
		if (sep_ls != NULL && !sep_loop)
			sep_ls = sep_ls->nextNode;
	}

  *sep_ls = *sep_list;
	*cmd_ls = *cmd_list;
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

/**
 * split_cmds - A function that splits command lines according to
 * separators ;, | and &, and executes them
 * @data_sh: (data structure) relevant data
 * @n: input string
 * Return: 0 to exit, 1 to continue
 */
int split_cmds(data_shell *data_sh, char *n)
{

	separ_list *sep_head, *sep_list;
	line_lst *cmd_head, *cmd_list;
	int loop;

	sep_head = NULL;
	cmd_head = NULL;

	add_sep_commands(&sep_head, &cmd_head, n);

	sep_list = sep_head;
	cmd_list = cmd_head;

	while (cmd_list != NULL)
	{
		data_sh->n = cmd_list->line;
		data_sh->args = split_string(data_sh->n);
		loop = _execline(data_sh);
		free(data_sh->args);

		if (loop == 0)
			break;

		nxt_cmd_line(&sep_list, &cmd_list, data_sh);

		if (cmd_list != NULL)
			cmd_list = cmd_list->nxtNode;
	}

	free_separ_list(&sep_head);
	free_line_lst(&cmd_head);

	if (loop == 0)
		return (0);
	return (1);
}