#include "shell.h"

/**
 * cdir_shell - a function that changes current directory
 * @data_sh: (Environment) relevant data
 * Return: 1 on success
 */
int cdir_shell(data_shell *data_sh)
{
	char *dir;
	int is_hme1, is_hme2, is_ddash;

	dir = data_sh->args[1];

	if (dir != NULL)
	{
		is_hme1 = _strgcmp("$HOME", dir);
		is_hme2 = _strgcmp("~", dir);
		is_ddash = _strgcmp("--", dir);
	}

	if (dir == NULL || !is_hme1 || !is_hme2 || !is_ddash)
	{
		cdToHome(data_sh);
		return (1);
	}

	if (_strgcmp("-", dir) == 0)
	{
		cdPrev(data_sh);
		return (1);
	}

	if (_strgcmp(".", dir) == 0 || _strgcmp("..", dir) == 0)
	{
		cdDot(data_sh);
		return (1);
	}
	cdTo(data_sh);

	return (1);
}