#include "shell.h"

/**
 * change_par_dir - a function that changes to the parent directory
 * @data_sh: relevant data environment
 * Return: no return
 */
void change_par_dir(data_shell *data_sh)
{
	char curr_path[PATH_MAX];
	char *cdir, *cpd_curr_path, *cpd_strgtok_curr_path;

	getcwd(curr_path, sizeof(curr_path));
	cpd_curr_path = _strgdup(curr_path);
	setEnv("OLDPWD", cpd_curr_path, data_sh);
	cdir = data_sh->args[1];
	if (_strgcmp(".", cdir) == 0)
	{
		setEnv("PWD", cpd_curr_path, data_sh);

		free(cpd_curr_path);
		return;
	}
	if (_strgcmp("/", cpd_curr_path) == 0)
	{
		free(cpd_curr_path);
		return;
	}
	cpd_strgtok_curr_path = cpd_curr_path;
	revStrg(cpd_strgtok_curr_path);
	cpd_strgtok_curr_path = _strgtok(cpd_strgtok_curr_path, "/");
	if (cpd_strgtok_curr_path != NULL)
	{
		cpd_strgtok_curr_path = _strgtok(NULL, "\0");
		if (cpd_strgtok_curr_path != NULL)
			revStrg(cpd_strgtok_curr_path);
	}
	if (cpd_strgtok_curr_path != NULL)
	{
		chdir(cpd_strgtok_curr_path);
		setEnv("PWD", cpd_strgtok_curr_path, data_sh);
	}
	else
	{
		chdir("/");
		setEnv("PWD", "/", data_sh);
	}
	data_sh->stat = 0;
	free(cpd_curr_path);
}
/**
 * change_dir - function that changes to a directory 
 * given by user
 * @data_sh: relevant data environment
 * Return: no return
 */
void change_dir(data_shell *data_sh)
{
	char curr_path[PATH_MAX];
	char *cdir, *cp_curr_path, *cpd_cdir;

	getcwd(curr_path, sizeof(curr_path));

	dir = data_sh->args[1];
	if (chdir(cdir) == -1)
	{
		_geterror(data_sh, 2);
		return;
	}

	cpd_curr_path = _strgdup(curr_path);
	setEnv("OLDPWD", cpd_curr_path, data_sh);

	cpd_cdir = _strgdup(cdir);
	setEnv("PWD", cpd_cdir, data_sh);

	free(cpd_curr_path);
	free(cpd_curr_path);

	data_sh->stat = 0;

	chdir(cdir);
}
/**
 * change_to_prev_dir - function that changes to the previous directory
 * @data_sh: relevant data environment
 * Return: no return
 */
void change_to_prev_dir(data_shell *data_sh)
{
	char curr_path[PATH_MAX];
	char *cpd_curr_path, *prev_oldpwd, *cpd_oldpwd, *cpd_newpwd;

	getcwd(curr_path, sizeof(curr_path));
	cpd_curr_path = _strgdup(curr_path);

	prev_oldpwd = get_envir("OLDPWD", data_sh->envir);

	if (prev_oldpwd == NULL)
		cpd_oldpwd = cpd_curr_path;
	else
		cpd_oldpwd = _strgdup(prev_oldpwd);

	setEnv("OLDPWD", cpd_curr_path, data_sh);

	if (chdir(cpd_oldpwd) == -1)
		setEnv("PWD", cpd_curr_path, data_sh);

	else
		setEnv("PWD", cpd_oldpwd, data_sh);

	cpd_newpwd = get_envir("PWD", data_sh->envir);

	write(STDOUT_FILENO, cpd_newpwd, _strglen(cpd_newpwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cpd_curr_path);
	if (prev_oldpwd)
		free(cpd_oldpwd);

	data_sh->stat = 0;

	chdir(cpd_newpwd);
}


/**
 * change_to_home_dir - function that changes to home directory
 * @data_sh: relevant data enevironment
 * Return: no return
 */
void change_to_home_dir(data_shell *data_sh)
{
	char *cpd_curr_path, *hme;
	char curr_path[PATH_MAX];

	getcwd(curr_path, sizeof(curr_path));
	cpd_curr_path = _strgdup(curr_path);

	hme = get_envir("HOME", data_sh->envir);

	if (hme == NULL)
	{
		setEnv("OLDPWD", cpd_curr_path, data_sh);
		free(cpd_curr_path);
		return;
	}

	if (chdir(hme) == -1)
	{
		_geterror(data_sh, 2);
		free(cpd_curr_path);
		return;
	}

	setEnv("OLDPWD", cpd_curr_path, data_sh);
	setEnv("PWD", hme, data_sh);
	free(cpd_curr_path);
	data_sh->stat = 0;
}