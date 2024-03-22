#include "shell.h"

/**
 * counts_repetition_of_char - Function that counts 
 * repetitions of a character
 * @s: input value
 * @index: index character
 * Return: Repetitions
 */
int counts_repetition of_char(char *s, int index)
{
	if (*(s - 1) == *s)
		return (counts_repetition_of_char(s - 1, index + 1));

	return (index);
}
/**
 *  fnds_syntax_err - function that finds syntax errors
 * @s: input value 
 * @index: index error
 * @prev_char: last character read
 * Return: index of error, 0 otherwise
 */
int fnds_syntax_err(char *s, int index, char prev_char)
{
	int result;

	result = 0;
	if (*s == '\0')
		return (0);

	if (*s == ' ' || *s == '\t')
		return (fnds_syntax_err(n + 1, index + 1, prev_char));

	if (*s == ';')
		if (prev_char == '|' || prev_char == '&' || prev_char == ';')
			return (index);

	if (*s == '|')
	{
		if (prev_char == ';' || prev_char == '&')
			return (index);

		if (last == '|')
		{
			result = counts_repetition_of_char(s, 0);
			if (result == 0 || result > 1)
				return (index);
		}
	}

	if (*s == '&')
	{
		if (prev_char == ';' || prev_char == '|')
			return (index);

		if (prev_char == '&')
		{
			result = counts_repetition_of_char(s, 0);
			if (result == 0 || result > 1)
				return (index);
		}
	}

	return (fnds_syntax_err(s + 1, index + 1, *s));
}

/**
 * fnds_first_char - function that finds index 
 * of first character
 * @s: input value
 * @index: index character
 * Return: 1 if there is an error, 0 otherwise
 */
int fnds_first_char(char *s, int *index)
{
	for (*index = 0; s[*index]; *index += 1)
	{
		if (s[*index] == ' ' || s[*index] == '\t')
			continue;

		if (s[*index] == ';' || s[*index] == '|' || s[*index] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * prt_syntax_err - Function that prints when 
 * a syntax error is found
 * @data_sh: relevant data structure for shell
 * @s: input value
 * @index: index of the error
 * @error_msg_ctrl: controls message error
 */
void prt_syntax_err(data_shell *data_sh, char *s, int index, int error_msg_ctrl)
{
	char *error_msg, *error_msg2, *error_msg3, *error_type, *result;
	int len;

	if (s[index] == ';')
	{
		if (error_msg_ctrl == 0)
			error_type = (s[index + 1] == ';' ? ";;" : ";");
		else
			error_type = (s[index + 1] == ';' ? ";;" : ";");
	}

	if (s[index] == '|')
		error_type = (s[index + 1] == '|' ? "||" : "|");
	if (s[index] == '&')
		error_type = (s[index + 1] == '&' ? "&&" : "&");

	error_msg2 = ": Syntax error: \"";
	error_msg3 = "\" unexpected\n";
	result = mili_itoa(data_sh->result);
	len = _strglen(data_sh->argv[0]) + _strglen(result);
	len += _strglen(error_type) + _strglen(error_msg2) + _strglen(error_msg3) + 2;

	error_msg = malloc(sizeof(char) * (len + 1));
	if (error_msg == 0)
	{
		free(result);
		return;
	}
	_strgcpy(error_msg, data_sh->argv[0]);
	_strgcat(error_msg, ": ");
	_strgcat(error_msg, result);
	_strgcat(error_msg, erro_msg2);
	_strgcat(error_msg, error_type);
	_strgcat(error_msg, error_msg3);
	_strgcat(error_msg, "\0");

	write(STDERR_FILENO, error_msg, len);
	free(error_msg);
	free(result);
}

/**
 * chck_for_syntax_error - intermediate function that
 * finds and prints a syntax error
 * @data_sh: relevant data structure for shell
 * @s: input value
 * Return: 1 if there is an error, 0 otherwise
 */
int chck_for_syntax_error(data_shell *data_sh, char *s)
{
	int start = 0;
	int firstChar = 0;
	int j = 0;

	firstChar = fnds_first_char(s, &start);
	if (first_char == -1)
	{
		prt_syntax_err(data_sh, s, start, 0);
		return (1);
	}
	j = fnds_syntax_err(s + start, 0, *(s + start));
	if (j != 0)
	{
		prt_syntax_err(data_sh, s, start + 1, 1);
		return (1);
	}

	return (0);
}