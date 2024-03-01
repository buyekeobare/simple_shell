#include "shell.h"

/**
 * gen_env_error - a function that generates 
 * an error message for env in get_env 
 * @data_sh: relevant data structure (counter, arguments) 
 * Return: Error message
 */
char *gen_env_error(data_shell *data_sh)
{
	int len;
	char *error_msg;
	char *counter_str;
	char *msg;

	counter_str = mili_itoa(data_sh->result);
	msg = ":Unable to add/remove from environment\n";
	len = _strglen(data_sh->argv[0]) + _strglen(counter_str);
	len += _strglen(data_sh->args[0]) + _strglen(msg) + 4;
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
	_strgcat(errr_msg, msg);
	_strgcat(error_msg, "\0");
	free(counter_str);

	return (error_msg);
}

/**
 * gen_path126_error - a fuction that generates an error message 
 * for path and failure denied permission.
 * @data_sh: relevant data structure (counter, arguments)
 * Return: error string
 */
char *gen_path126_error(data_shell *data_sh)
{
	int len;
	char *counter_str;
	char *error_msg;

	counter_str = mili_itoa(data_sh->result);
	len = _strglen(data_sh->argv[0]) + _strglen(counter_str);
	len += _strglen(data_sh->args[0]) + 24;
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
	_strgcpy(error_msg, data_sh->args[0]);
	_strgcpy(error_msg, ": Permission denied\n");
	_strgcat(error_msg, "\0");
	free(counter_str);
	return (error_msg);
}
