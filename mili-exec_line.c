#include "shell.h"

/**
 * _execline - a function that finds builtins and commands
 * @datash: (args) relevant data 
 * Return: 1 on success.
 */
int _execline(data_shell *data_sh)
{
	int (*_builtin)(data_shell *data_sh);

	if (data_sh->args[0] == NULL)
		return (1);

	_builtin = _getbuiltin(data_sh->args[0]);

	if (_builtin != NULL)
		return (_builtin(data_sh));

	return (exec_cmd(data_sh));
}