#include "shell.h"

/**
 * helpEnv - Displays information about builtin command 'env'
 * Return: no return
 */
void helpEnv(void)
{
	char *flow = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "Prints the current environment.\n";
	write(STDOUT_FILENO, flow, _strglen(flow));
}
/**
 * helpSetenv - Displays information about builtin command 'setenv'
 * Return: no return
 */
void helpSetenv(void)
{

	char *flow = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "int replace)\n\t";
	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "Adds a new definition to the environment\n";
	write(STDOUT_FILENO, flow, _strglen(flow));
}
/**

 * helpUnsetenv - Displays information about builtin command 'unsetenv'
 * Return: no return
 */
void helpUnsetenv(void)
{
	char *flow = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, flow, _strglen(flow));
}

/**
 * genHelp - Displays information about builtin command 'help'
 * Return: no return
 */
void genHelp(void)
{
	char *flow = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "Type 'help name' to find out more about the function 'name'.\n\n";
	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "[dir]\nexit: exit [n]\n env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "[args]]\n setenv: setenv [variable] [value]\n unsetenv: ";
	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "unsetenv [variable]\n";
	write(STDOUT_FILENO, flow, _strglen(flow));
}
/**
 * exitHelp - Displays information about builtin command 'exit'
 * Return: no return
 */
void exitHelp(void)
{
	char *flow = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "Exits the shell with status N. If N is omitted, exit";
	write(STDOUT_FILENO, flow, _strglen(flow));
	flow = "status is for the last command executed\n";
	write(STDOUT_FILENO, flow, _strglen(flow));
}