#include "shell.h"

/**
 * _geterror - a function that calls the error according 
 * the builtin, syntax or permission.
 * @data_sh: (structure) relevant data
 * @error_val: error value
 * Return: error value
 */
int _geterror(data_shell *data_sh, int error_val)
{
	char *error_msg;

	switch (error_val)
	{
	case -1:
		error_msg = gen_env_error(data_sh);
		break;
	case 126:
		error_msg = gen_path126_error(data_sh);
		break;
	case 127:
		error_msg = gen_not_found_error(data_sh);
		break;
	case 2:
		if (_strgcmp("exit", data_sh->args[0]) == 0)
			error_msg = gen_exit_shell_error(data_sh);
		else if (_strgcmp("cd", data_sh->args[0]) == 0)
			error_msg = gen_cd_error(data_sh);
		break;
	}

	if (error_msg)
	{
		write(STDERR_FILENO, error_msg, _strglen(error_msg));
		free(error_msg);
	}

	data_sh->stat = error_val;
	return (error_val);
}