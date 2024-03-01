#include "shell.h"

/**
 * cdDot - a function that changes to the parent directory
 * @data_sh: (environment) relevant data
 */
void cdDot(data_shell *data_sh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strgtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strgdup(pwd);
	setEnv("OLDPWD", cp_pwd, data_sh);
	dir = data_sh->args[1];
	if (_strgcmp(".", dir) == 0)
	{
		setEnv("PWD", cp_pwd, data_sh);

		free(cp_pwd);
		return;
	}
	if (_strgcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strgtok_pwd = cp_pwd;
	revStrg(cp_strgtok_pwd);
	cp_strgtok_pwd = _strgtok(cp_strgtok_pwd, "/");
	if (cp_strgtok_pwd != NULL)
	{
		cp_strgtok_pwd = _strgtok(NULL, "\0");
		if (cp_strgtok_pwd != NULL)
			revStrg(cp_strgtok_pwd);
	}
	if (cp_strgtok_pwd != NULL)
	{
		chdir(cp_strgtok_pwd);
		setEnv("PWD", cp_strgtok_pwd, data_sh);
	}
	else
	{
		chdir("/");
		setEnv("PWD", "/", data_sh);
	}
	data_sh->stat = 0;
	free(cp_pwd);
}
/**
 * cdTo - function that changes to a directory 
 * given by user
 * @data_sh: (Environment) relevant data
 */
void cdTo(data_shell *data_sh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = data_sh->args[1];
	if (chdir(dir) == -1)
	{
		get_err(data_sh, 2);
		return;
	}

	cp_pwd = _strgdup(pwd);
	setEnv("OLDPWD", cp_pwd, data_sh);

	cp_dir = _strgdup(dir);
	setEnv("PWD", cp_dir, data_sh);

	free(cp_pwd);
	free(cp_dir);

	data_sh->stat = 0;

	chdir(dir);
}
/**
 * cdPrev - function that changes to the previous directory
 * @data_sh: (environment) relevant data
 */
void cdPrev(data_shell *data_sh)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strgdup(pwd);

	p_oldpwd = get_envir("OLDPWD", data_sh->envir);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strgdup(p_oldpwd);

	setEnv("OLDPWD", cp_pwd, data_sh);

	if (chdir(cp_oldpwd) == -1)
		setEnv("PWD", cp_pwd, data_sh);

	else
		setEnv("PWD", cp_oldpwd, data_sh);

	p_pwd = get_envir("PWD", data_sh->envir);

	write(STDOUT_FILENO, p_pwd, _strglen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	data_sh->stat = 0;

	chdir(p_pwd);
}
/**
 * cdToHome - fucntion that changes to home directory
 * @data_sh: (environment) relevant data
 */
void cdToHome(data_shell *data_sh)
{
	char *p_pwd, *hme;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strgdup(pwd);

	hme = get_envir("HOME", data_sh->envir);

	if (hme == NULL)
	{
		setEnv("OLDPWD", p_pwd, data_sh);
		free(p_pwd);
		return;
	}

	if (chdir(hme) == -1)
	{
		get_err(data_sh, 2);
		free(p_pwd);
		return;
	}

	setEnv("OLDPWD", p_pwd, data_sh);
	setEnv("PWD", hme, data_sh);
	free(p_pwd);
	data_sh->stat = 0;
}