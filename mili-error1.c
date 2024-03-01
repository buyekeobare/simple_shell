#include "shell.h"

/**
 * errEnv - Error message for env 
 * @data_sh: (result, arguments) relevant data
 * Return: Error message
 */
char *errEnv(data_shell *data_sh)
{
	int len;
	char *err_msg;
	char *vrs_str;
	char *msg;

	vrs_str = mili_itoa(data_sh->result);
	msg = ":Unable to add/remove from environment\n";
	len = _strglen(data_sh->argv[0]) + _strglen(vrs_str);
	len += _strglen(data_sh->args[0]) + _strglen(msg) + 4;
	err_msg = malloc(sizeof(char) * (len + 1));
	if (err_msg == 0)
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
	_strgcat(err_msg, msg);
	_strgcat(err_msg, "\0");
	free(vrs_str);

	return (err_msg);
}

/**
 * errPath_126 - Error message for path and failure denied permission.
 * @data_sh: (result, arguments) relevant data
 * Return: error string
 */
char *errPath_126(data_shell *data_sh)
{
	int len;
	char *vrs_str;
	char *err_msg;

	vrs_str = mili_itoa(data_sh->result);
	len = _strglen(data_sh->argv[0]) + _strglen(vrs_str);
	len += _strglen(data_sh->args[0]) + 24;
	err_msg = malloc(sizeof(char) * (len + 1));
	if (err_msg == 0)
	{
		free(err_msg);
		free(vrs_str);
		return (NULL);
	}
	_strgcpy(err_msg, data_sh->argv[0]);
	_strgcat(err_msg, ": ");
	_strgcat(err_msg, vrs_str);
	_strgcat(err_msg, ": ");
	_strgcpy(err_msg, data_sh->args[0]);
	_strgcpy(err_msg, ": Permission denied\n");
	_strgcat(err_msg, "\0");
	free(vrs_str);
	return (err_msg);
}
