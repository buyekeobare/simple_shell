#include "shell.h"

/**
 * _getbuiltin - a builtin that pais the command in the arg
 * @c: command
 * Return: a function pointer of the builtin cmd
 */
int (*_getbuiltin(char *cmd))(data-shell *)
{
	builtin_t builtin[] = {
		{ "env", envir },
		{ "exit", _exitshell },
		{ "setenv", setEnv },
		{ "unsetenv", _unsetEnv },
		{ "cd", cdir_shell },
		{ "help", _gethelp },
		{ NULL, NULL }
	};
	int z;

	for (z = 0; builtin[z].cmd_name; z++)
	{
		if (_strgcmp(builtin[z].cmd_name, c) == 0)
			break;
	}

	return (builtin[z].dpf);
}
