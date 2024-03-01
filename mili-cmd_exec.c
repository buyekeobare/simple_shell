#include "shell.h"

/**
 * is_cd - function that checks ":" 
 * if it is in the current directory
 * @path: pointer character, type character
 * @i: pointer of index, type integer
 * Return: 1 if the path is searchable in the 
 * current directory, 0 otherwise
 */
int is_cd(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;
	return (0);
}

/**
 * which - a function that locates a command
 * @cmd: command name
 * @envir: environment variable
 * Return: location of the command
 */
char *which(char *cmd, char **envir)
{
	char *path, *ptr_path, *token_path, *dir;

	int length_dir, length_cmd, i;
	struct stat st;

	path = get_envir("PATH", envir);
	if (path)
	{
		ptr_path = _strgdup(path);
		length_cmd = _strglen(cmd);
		token_path = _strgtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cd(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			length_dir = _strglen(token_path);
			dir = malloc(length_dir + length_cmd + 2);
			_strgcpy(dir, token_path);
			_strgcat(dir, "/");
			_strgcat(dir, cmd);
			_strgcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strgtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_exec - function that determines if its an executable
 * @data_sh: (structure) relevant data
 * Return: 0 if not an executable, other number if it is
 */
int is_exec(data_shell *data_sh)
{
	struct stat st;
	int i;
	char *n;

	n = data_sh->args[0];
	for (i = 0; n[i]; i++)
	{
		if (n[i] == '.')
		{
			if (n[i + 1] == '.')
				return (0);
			if (n[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (n[i] == '/' && i != 0)

		{
			if (n[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(n + i, &st) == 0)
	{
		return (i);
	}
	get_err(data_sh, 127);
	return (-1);
}

/**
 * check_err_cmd - function that verifies 
 * if user has permissions to access
 * @ddir: destination directory
 * @data_sh: (structure) relevant data
 * Return: 1 if there is an error, 0 if not
 */
int check_err_cmd(char *ddir, data-shell *data_sh)
{
	if (ddir == NULL)
	{
		get_err(data_sh, 127);
		return (1);
	}

	if (_strgcmp(data_sh->args[0], ddir) != 0)
	{
		if (access(ddir, X_OK) == -1)
		{
			get_err(data_sh, 126);
			free(ddir);
			return (1);
		}
		free(ddir);
	}
	else
	{
		if (access(data_sh->args[0], X_OK) == -1)
		{
			get_err(data_sh, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_executable - function that executes command lines
 * @data_sh: (args & inputs) relevant data
 * Return: 1 on success
 */
int cmd_executable(data_shell *data_sh)
{
	pid_t pd_t;
	pid_t wpd_t;
	int state;
	int exec;
	char *ddir;
	(void) wpd;

	exec = is_exec(data_sh);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		ddir = _which(data_sh->args[0], data_sh->envir);
		if (check_err_cmd(ddir, data_sh) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			ddir = _which(data_sh->args[0], data_sh->envir);
		else
			ddir = data_sh->args[0];
		execve(dir + exec, data_sh->args, data_sh->envir);
	}
	else if (pd < 0)
	{
		perror(data_sh->argvec[0]);
		return (1);
	}
	else
	{
		do {
			wpd_t = waitpid(pd_t, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	data_sh->stat = state / 256;
	return (1);
}