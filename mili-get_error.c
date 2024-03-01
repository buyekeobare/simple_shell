#include "shell.h"

/**
 * get_err - a function that calls the error according 
 * the builtin, syntax or permission.
 * @data_sh: (structure) relevant data
 * @err_val: error value
 * Return: error value
 */
int get_err(data_shell *data_sh, int err_val)
{
	char *err;

	switch (err_val)
	{
	case -1:
		err = errEnv(data_sh);
		break;
	case 126:
		err = errPath_126(data_sh);
		break;
	case 127:
		err = errNot_found(data_sh);
		break;
	case 2:
		if (_strgcmp("exit", data_sh->args[0]) == 0)
			err = errExit_shell(data_sh);
		else if (_strgcmp("cd", data_sh->args[0]) == 0)
			err = errGet_cd(data_sh);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strglen(err));
		free(err);
	}

	data_sh->stat = err_val;
	return (err_val);
}