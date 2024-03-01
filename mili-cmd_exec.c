#include "shell.h"

/**
 * is_colon_cdir - function that checks ":" 
 * if it is in the current directory
 * @curr_path: pointer character, type character
 * @curr_index: pointer of index, type integer
 * Return: 1 if the path is searchable in the 
 * current directory, 0 otherwise
 */
int is_colon_cdir(char *curr_path, int *curr_index)
{
	if (curr_path[*curr_index] == ':')
		return (1);

	while (curr_path[*curr_index] != ':' && curr_path[*curr_index])
	{
		*curr_index += 1;
	}

	if (curr_path[*curr_index])
		*curr-index += 1;
	return (0);
}

/**
 * locates_command - a function that locates a command
 * @cmd: command name
 * @envir: environment variable
 * Return: location of the command
 */
char *locates_command(char *cmd, char **envir)
{
	char *path, *path_cpy, *path_token, *directory;

	int dir_length, cmd_length, i;
	struct stat file_stat;

	path = get_envir("PATH", envir);
	if (path)
	{
		path_cpy = _strgdup(path);
		length_cmd = _strglen(cmd);
		path_token = _strgtok(path_cpy, ":");
		i = 0;
		while (path_path != NULL)
		{
			if (is_cd(path, &i))
				if (stat(cmd, &file_stat) == 0)
					return (cmd);
			dir_length = _strglen(path_token);
			dir = malloc(dir_length + cmd_length + 2);
			_strgcpy(directory, path_token);
			_strgcat(directory, "/");
			_strgcat(directory, cmd);
			_strgcat(directory, "\0");
			if (stat(directory, &file_stat) == 0)
			{
				free(path_cpy);
				return (directory);
			}
			free(directory);
			path_token = _strgtok(NULL, ":");
		}
		free(path_cpy);
		if (stat(cmd, &file_stat) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &file_stat) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_exec - function that determines if its an executable
 * @data_sh: relevant data structure for shell
 * Return: 0 if not an executable, other number if it is
 */
int is_exec(data_shell *data_sh)
{
	struct stat file_stat;
	int index;
	char *n;

	n = data_sh->args[0];
	for (index = 0; n[index]; index++)
	{
		if (n[index] == '.')
		{
			if (n[index + 1] == '.')
				return (0);
			if (n[index + 1] == '/')
				continue;
			else
				break;
		}
		else if (n[index] == '/' && index != 0)

		{
			if (n[index + 1] == '.')
				continue;
			index++;
			break;
		}
		else
			break;
	}
	if (index == 0)
		return (0);

	if (stat(n + index, &file_stat) == 0)
	{
		return (index);
	}
	_geterror(data_sh, 127);
	return (-1);
}

/**
 * check_cmd_error - function that verifies 
 * if user has permissions to access
 * @ddir: destination directory
 * @data_sh: relevant data structure for shell
 * Return: 1 if there is an error, 0 if not
 */
int check_cmd_error(char *ddir, data-shell *data_sh)
{
	if (ddir == NULL)
	{
		_geterror(data_sh, 127);
		return (1);
	}

	if (_strgcmp(data_sh->args[0], ddir) != 0)
	{
		if (access(ddir, X_OK) == -1)
		{
			_geterror(data_sh, 126);
			free(ddir);
			return (1);
		}
		free(ddir);
	}
	else
	{
		if (access(data_sh->args[0], X_OK) == -1)
		{
			_geterror(data_sh, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * exec_cmd - function that executes command lines
 * @data_sh: relevant data structure for shell (args & inputs) 
 * Return: 1 on success
 */
int exec_cmd(data_shell *data_sh)
{
	pid_t processID;
	pid_t waitProcessID;
	int processState;
	int exec_index;
	char *ddir;
	(void) waitProcessID;

	exec_index = is_exec(data_sh);
	if (exec_index == -1)
		return (1);
	if (exec_index == 0)
	{
		ddir = locates_command(data_sh->args[0], data_sh->envir);
		if (check_cmd_error(ddir, data_sh) == 1)
			return (1);
	}

	processID = fork();
	if (processID == 0)
	{
		if (exec_index == 0)
			ddir = locates_command(data_sh->args[0], data_sh->envir);
		else
			ddir = data_sh->args[0];
		execve(ddir + exec_index, data_sh->args, data_sh->envir);
	}
	else if (processID < 0)
	{
		perror(data_sh->argv[0]);
		return (1);
	}
	else
	{
		do {
			waitProcessID = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	data_sh->stat = state / 256;
	return (1);
}
