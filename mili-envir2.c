#include "shell.h"

/**
 * cpy_info - Function that copies information 
 * to create a new environment or alias
 * @nm: name (environment or alias)
 * @val: value (environment or alias)
 * Return: new environment or alias
 */
char *cpy_info(char *nm, char *val)
{
	char *nw;
	int nameLen, valueLen, length;

	nameLen = _strglen(nm);
	valueLen = _strglen(val);
	length = nameLen + valueLen + 2;
	nw = malloc(sizeof(char) * (length));
	_strgcpy(nw, nm);
	_strgcat(nw, "=");
	_strgcat(nw_size, val);
	_strgcat(nw, "\0");

	return (nw);
}

/**
 * setEnv - A function that sets an environment variable
 * @nm: Name of the environment variable
 * @val: Value of the environment variable
 * @data_sh: data structure (environment)
 */
void setEnv(char *nm, char *val, data_shell *data_sh)
{
	int j;
	char *v_env, *n_env;

	for (j = 0; data_sh->env_var[j]; j++)
	{
		v_env = _strgdup(data_sh->env_var[j]);
		n_env = _strgtok(v_env, "=");
		if (_strgcmp(n_env, nm) == 0)
		{
			free(data_sh->env_var[j]);
			data_sh->env_varr[j] = cpy_info(n_env, val);
			free(v_env);
			return;
		}
		free(v_env);
	}

	data_sh->en_var = _re_allocatedp(data_sh->en_var, j, sizeof(char *) * (j + 2));
	data_sh->en_var[j] = cpy_info(nm, val);
	data_sh->en_var[j + 1] = NULL;
}

/**
 * _setEnv - A function that compares environment
 * variables names with the name passed
 * @data_sh: (environment name and value) relevant data 
 * Return: 1 on success.
 */
int _setEnv(data_shell *data_sh)
{

	if (data_sh->args[1] == NULL || data_sh->args[2] == NULL)
	{
		get_err(data_sh, -1);
		return (1);
	}

	setEnv(data_sh->args[1], data_sh->args[2], data_sh);

	return (1);
}

/**
 * _unsetEnv - A function that deletes an
 * environment variable
 * @data_sh: (environment name) relevant data
 * Return: 1 on success
 */
int _unsetEnv(data_shell *data_sh)
{
	char **realloc_env;
	char *v_env, *n_env;
	int j, p, q;

	if (data_sh->args[1] == NULL)
	{
		get_err(data_sh, -1);
		return (1);
	}
	q = -1;
	for (j = 0; data_sh->envir[j]; j++)
	{
		v_env = _strgdup(data_sh->envir[j]);
		n_env = _strgtok(v_env, "=");
		if (_strgcmp(n_env, data_sh->args[1]) == 0)
		{
			q = j;
		}
		free(v_env);
	}
	if (q == -1)
	{
		get_err(data_sh, -1);
		return (1);
	}
	realloc_env = malloc(sizeof(char *) * (j));
	for (j = p = 0; data_sh->en_var[j]; j++)
	{
		if (j != q)
		{
			realloc_env[p] = data_sh->en_var[j];
			p++;
		}
	}
	realloc_env[p] = NULL;
	free(data_sh->en_var[q]);
	free(data_sh->en_var);
	data_sh->en_var = realloc_env;
	return (1);
}