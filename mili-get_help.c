#include "shell.h"

/**
 * _gethelp - retrieves help messages according to the builtin
 * @data_sh: (args and input) relevant data
*/
int _gethelp(data_shell *data_sh)
{

	if (data_sh->args[1] == 0)
		genHelp();
	else if (_strgcmp(data_sh->args[1], "setenv") == 0)
		helpSetenv();
	else if (_strgcmp(data_sh->args[1], "env") == 0)
		helpEnv();
	else if (_strgcmp(data_sh->args[1], "unsetenv") == 0)
		helpUnsetenv();
	else if (_strgcmp(data_sh->args[1], "help") == 0)
		help_cmd();
	else if (_strgcmp(data_sh->args[1], "exit") == 0)
		exitHelp();
	else if (_strgcmp(data_sh->args[1], "cd") == 0)
		cd_help();
	else if (_strgcmp(data_sh->args[1], "alias") == 0)
		alias_help();
	else
		write(STDERR_FILENO, data_sh->args[0],
		      _strglen(data_sh->args[0]));

	data_sh->stat = 0;
	return (1);
}
