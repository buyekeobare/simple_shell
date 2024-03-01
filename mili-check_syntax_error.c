#include "shell.h"

/**
 * char_repeated - Function that counts 
 * repetitions of a character
 * @n: input value
 * @index: index character
 * Return: Repetitions
 */
int char_repeated(char *n, int index)
{
	if (*(n - 1) == *n)
		return (char_repeated(n - 1, index + 1));

	return (index);
}
/**
 * err_sp_op - function that finds syntax errors
 * @n: input value 
 * @index: index error
 * @lst: last character read
 * Return: index of error, 0 otherwise
 */
int err_sp_op(char *n, int index, char lst)
{
	int result;

	result = 0;
	if (*n == '\0')
		return (0);

	if (*n == ' ' || *n == '\t')
		return (err_sp_op(n + 1, index + 1, lst));

	if (*n == ';')
		if (lst == '|' || lst == '&' || lst == ';')
			return (index);

	if (*n == '|')
	{
		if (lst == ';' || lst == '&')
			return (index);

		if (last == '|')
		{
			result = char_repeated(n, 0);
			if (result == 0 || result > 1)
				return (index);
		}
	}

	if (*n == '&')
	{
		if (lst == ';' || lst == '|')
			return (index);

		if (lst == '&')
		{
			result = char_repeated(n, 0);
			if (result == 0 || result > 1)
				return (index);
		}
	}

	return (err_sp_op(n + 1, index + 1, *n));
}

/**
 * frst_chr - function that finds index 
 * of first character
 * @n: input value
 * @index: index character
 * Return: 1 if there is an error, 0 otherwise
 */
int frst_chr(char *n, int *index)
{
	for (*index = 0; n[*index]; *index += 1)
	{
		if (n[*index] == ' ' || n[*index] == '\t')
			continue;

		if (n[*index] == ';' || n[*index] == '|' || n[*index] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * prt_syntax_err - Function that prints when 
 * a syntax error is found
 * @data_sh: (structure) relevant data
 * @n: input value
 * @index: index of the error
 * @bool: controls message error
 */
void prt_syntax_err(data_shell *data_sh, char *n, int index, int bool)
{
	char *msg1, *msg2, *msg3, *err, *result;
	int len;

	if (n[index] == ';')
	{
		if (bool == 0)
			msg1 = (n[index + 1] == ';' ? ";;" : ";");
		else
			msg1 = (n[index + 1] == ';' ? ";;" : ";");
	}

	if (n[index] == '|')
		msg1 = (n[index + 1] == '|' ? "||" : "|");
	if (n[index] == '&')
		msg1 = (n[index + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	result = mili_itoa(data_sh->result);
	len = _strglen(data_sh->argv[0]) + _strglen(result);
	len += _strglen(msg) + _strglen(msg2) + _strglen(msg3) + 2;

	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(result);
		return;
	}
	_strgcpy(err, data_sh->argv[0]);
	_strgcat(err, ": ");
	_strgcat(err, result);
	_strgcat(err, msg2);
	_strgcat(err, msg1);
	_strgcat(err, msg3);
	_strgcat(err, "\0");

	write(STDERR_FILENO, err, len);
	free(err);
	free(result);
}
/**
 * chck_syntax_err - intermediate function that
 * finds and prints a syntax error
 * @data_sh: (structure) relevant data
 * @n: input value
 * Return: 1 if there is an error, 0 otherwise
 */
int chck_syntax_err(data_shell *data_sh, char *n)
{
	int start = 0;
	int f_chr = 0;
	int j = 0;

	f_chr = frst_chr(n, &start);
	if (f_chr == -1)
	{
		prt_syntax_err(data_sh, n, start, 0);
		return (1);
	}
	j = err_sp_op(n + start, 0, *(n + start));
	if (j != 0)
	{
		prt_syntax_err(data_sh, n, start + 1, 1);
		return (1);
	}

	return (0);
}