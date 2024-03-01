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
		err = gen_env_error(data_sh);
		break;
	case 126:
		err = gen_path126_error(data_sh);
		break;
	case 127:
		err = gen_not_found_error(data_sh);
		break;
	case 2:
		if (_strgcmp("exit", data_sh->args[0]) == 0)
			err = gen_exit_shell_error(data_sh);
		else if (_strgcmp("cd", data_sh->args[0]) == 0)
			err = gen_cd_error(data_sh);
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