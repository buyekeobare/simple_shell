#include "shell.h"

/**
 * _exitshell - functions that exits the shell
 * @data_sh: (status and args) relevant data
 */
int _exitshell(data_shell *data_sh)
{
	unsigned int u_stat;
	int isdigit;
	int strglen;
	int bignum;

	if (datash->args[1] != NULL)
	{
		u_stat = mili_atoi(data_sh->args[1]);
		isdigit = _isdigit(data_sh->args[1]);
		strglen = _strglen(data_sh->args[1]);
		bignum = u_stat > (unsigned int)INT_MAX;
		if (!isdigit || strglen > 10 || bignum)
		{
			get_err(data_sh, 2);
			data_sh->stat = 2;
			return (1);
		}
		data_sh->stat = (u_stat % 256);
	}
	return (0);
}