#include "shell.h"

/**
 * strgcat_cd - The function that concatenates message for cd error
 * @data_sh: (directory) relevant data
 * @msg: message to print
 * @err_msg: output message
 * @vrs_str: counter lines
 * Return: error message
 */
char *strgcat_cd(data_shell *data_sh, char *msg, char *err_msg, char *vrs_str)

{
	char *illegal_flag;

	_strgcpy(err_msg, data_sh->argv[0]);
	_strgcat(err_msg, ": ");
	_strgcat(err_msg, vrs_str);
	_strgcat(err_msg, ": ");
	_strgcat(err_msg, data_sh->args[0]);
	_strgcat(err_msg, msg);
	if (data_sh->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = data_sh->args[1][1];
		illegal_flag[2] = '\0';
		_strgcat(err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strgcat(err, data_sh->args[1]);
	}

	_strgcat(err_msg, "\n");
	_strgcat(err_msg, "\0");
	return (err_msg);
}

/**
 * errGet_cd - The error message for cd command in get_cd
 * @data_sh: (directory) relevant data
 * Description - prints an error message for cd
 * Return: Error message
 */
char *errGet_cd(data_shell *data_sh)
{
	int len, len_id;
	char *err_msg, *vrs_str, *msg;

	vrs_str = mili_itoa(data_sh->result);
	if (data_sh->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strglen(data_sh->args[1]);
	}

	len = _strglen(data_sh->argv[0]) + _strglen(data_sh->args[0]);
	len += _strglen(vrs_str) + _strglen(msg) + len_id + 5;
	err_msg = malloc(sizeof(char) * (len + 1));

	if (err_msg == 0)
	{
		free(vrs_str);
		return (NULL);
	}

	err_msg = strgcat_cd(data_sh, msg, err_msg, vrs_str);

	free(vrs_str);

	return (err_msg);
}

/**
 * errNot_found - The generic error message for command not found
 * @data_sh: (result, arguments) relevant data
 * Description - prints an error message for command not found
 * Return: error message
 */
char *errNot_found(data_shell *data_sh)
{
	int len;
	char *err_msg;
	char *vrs_str;

	vrs_str = mili_itoa(data_sh->result);
	len = _strglen(data_sh->argv[0]) + _strglen(vrs_str);
	len += _strglen(data_sh->args[0]) + 16;
	err_msg = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err_msg);
		free(vrs_str);
		return (NULL);
	}
	_strgcpy(err_msg, data_sh->argv[0]);
	_strgcat(err_msg, ": ");
	_strgcat(err_msg, vrs_str);
	_strgcat(err_msg, ": ");
	_strgcat(err_msg, data_sh->args[0]);
	_strgcat(err_msg, ": not found\n");
	_strgcat(err_msg, "\0");
	free(vrs_str);
	return (err);
}

/**
 * errExit_shell - The generic error message for exit in getExit
 * @data_sh: (result, arguments) relevant data
 * Description - prints error message for exit in getExit
 * Return: error message
 */
char *errExit_shell(data_shell *data_sh)
{
	int len;
	char *err_msg;
	char *vrs_str;

	vrs_str = mili_itoa(data_sh->result);
	len = _strglen(data_sh->argv[0]) + _strglen(vrs_str);
	len += _strglen(data_sh->args[0]) + _strglen(data_sh->args[1]) + 23;
	err_msg = malloc(sizeof(char) * (len + 1));
	if (err_msg == 0)
	{
		free(vrs_str);
		return (NULL);
	}
	_strgcpy(err_msg, data_sh->argv[0]);
	_strgcat(err_msg, ": ");
	_strgcat(err_msg, vrs_str);
	_strgcat(err_msg, ": ");
	_strgcat(err_msg, data_sh->args[0]);
	_strgcat(err_msg, ": Illegal number: ");
	_strgcat(err_msg, data_sh->args[1]);
	_strgcat(err_msg, "\n\0");
	free(vrs_str);

	return (err_msg);
}
