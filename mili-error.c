#include "shell.h"

/**
 * strgcat_cd - The function that concatenates message for cd error
 *
 * @data_sh: relevant data structure
 * @msg: message to print
 * @error_msg: output message
 * @counter_str: counter lines
 * Return: error message
 */
char *strgcat_cd(data_shell *data_sh, char *msg, char *error_msg, char *counter_str)

{
	char *illegal_flag;

	_strgcpy(error_msg, data_sh->argv[0]);
	_strgcat(error_msg, ": ");
	_strgcat(error_msg, counter_str);
	_strgcat(error_msg, ": ");
	_strgcat(error_msg, data_sh->args[0]);
	_strgcat(error_msg, msg);

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
		_strgcat(error_msg, data_sh->args[1]);
	}

	_strgcat(error_msg, "\n");
	_strgcat(error_msg, "\0");
	return (error_msg);
}

/**
 * gen_cd_error - a function that generates error 
 * message for cd command in get_cd
 * @data_sh: relevant data structure for shell
 * Description - prints an error message for cd
 * Return: Error message
 */
char *gen_cd_error(data_shell *data_sh)
{
	int len, length_id;
	char *error_msg, *counter_str, *msg;

	counter_str = mili_itoa(data_sh->result);
	if (data_sh->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		length_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		length_id = _strglen(data_sh->args[1]);
	}

	len = _strglen(data_sh->argv[0]) + _strglen(data_sh->args[0]);
	len += _strglen(counter_str) + _strglen(msg) + length_id + 5;
	error_msg = malloc(sizeof(char) * (len + 1));

	if (error_msg == 0)
	{
		free(counter_str);
		return (NULL);
	}

	error_msg = strgcat_cd(data_sh, msg, error_msg, counter_str);

	free(counter_str);

	return (error_msg);
}

/**
 * gen_not_found_error - a function that generates 
 * error message for command not found
 * @data_sh: Relevant data structure (counter, arguments) 
 * Description - prints an error message for command not found
 * Return: error message
 */
char *gen_not_found_error(data_shell *data_sh)
{
	int len;
	char *error_msg;
	char *counter_str;

	counter_str = mili_itoa(data_sh->result);
	len = _strglen(data_sh->argv[0]) + _strglen(counter_str);
	len += _strglen(data_sh->args[0]) + 16;
	error_msg = malloc(sizeof(char) * (len + 1));
	if (error_msg == 0)
	{
		free(error_msg);
		free(counter_str);
		return (NULL);
	}
	_strgcpy(error_msg, data_sh->argv[0]);
	_strgcat(error_msg, ": ");
	_strgcat(error_msg, counter_str);
	_strgcat(error_msg, ": ");
	_strgcat(error_msg, data_sh->args[0]);
	_strgcat(error_msg, ": not found\n");
	_strgcat(error_msg, "\0");
	free(counter_str);
	return (error_msg);
}

/**
 * gen_exit_shell_error - The generic error message for exit in getExit
 * @data_sh: Relevant data structure (counter, arguments)
 * Description - prints error message for exit in getExit
 * Return: error message
 */
char *gen_exit_shell_error(data_shell *data_sh)
{
	int len;
	char *error_msg;
	char *counter_str;

	counter_str = mili_itoa(data_sh->result);
	len = _strglen(data_sh->argv[0]) + _strglen(counter_str);
	len += _strglen(data_sh->args[0]) + _strglen(data_sh->args[1]) + 23;
	error_msg = malloc(sizeof(char) * (len + 1));
	if (error_msg == 0)
	{
		free(counter_str);
		return (NULL);
	}
	_strgcpy(error_msg, data_sh->argv[0]);
	_strgcat(error_msg, ": ");
	_strgcat(error_msg, counter_str);
	_strgcat(error_msg, ": ");
	_strgcat(error_msg, data_sh->args[0]);
	_strgcat(error_msg, ": Illegal number: ");
	_strgcat(error_msg, data_sh->args[1]);
	_strgcat(error_msg, "\n\0");
	free(counter_str);

	return (error_msg);
}
