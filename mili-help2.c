#include "shell.h"

/**
 * help_cmd - Displays information about the builtin command help
 */
void help_cmd (void)
{
	char *flow = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "\tDisplays information about builtin commands.\n";
	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "Displays brief summaries of builtin commands.\n ";
	write(STDOUT_FILENO, flow, _strglen(flow));
}

/**
 * alias_help - Displays information about the builtin command alias
 */
void alias_help(void)
{
	char *flow = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "\tDefines or displays aliases.\n ";
	write(STDOUT_FILENO, flow, _strglen(flow));
}

/**
 * cd_help - Displays information about the builtin command cd
 */
void cd_help(void)
{
	char *flow = "cd: cd [-L|[-P [-e]] [ -@]] [dir]\n";

	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "\tChanges the current directory of the shell.\n ";
	write(STDOUT_FILENO, flow, _strglen(flow));
}