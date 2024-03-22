#include "shell.h"

/**
 * compare_envir_var_name - a function that compares environment 
 * variables' names with the name passed
 * @envir_var_name: name of the environment variable
 * @nm: name passed
 * Return: 0 if are not equal, another value if otherwise
 */
int compare_envir_var_name(const char *envir_var_name, const char *nm)
{
	int j;

	for (j = 0; envir_var_name[j] != '='; j++)
	{
		if (envir_var_name[j] != nm[j])
		{
			return (0);
		}
	}

	return (j + 1);
}
/**
 * get_envir_var - function that gets an environment variable
 * @envir_var_name: name of the environment variable
 * @envir_var: environment variable
 * Return: value of the environment variable if found,
 * otherwise return NULL
 */
char *get_envir_var(const char *envir_var_name, char **envir_var)
{
	char *p_env;
	int i, mv;

	/* initialize p_env value */
	p_env = NULL;
	mv = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; envir_var[i]; i++)
	{
		/* If name & envir are equal */
		mv = cmp_envir_nm(envir_var[i], envir_var_name);
		if (mv)
		{
			p_env = envir_var[i];
			break;
		}
	}

	return (p_env + mv);
}
/**
 * prints_envir_var - function that prints the environment variables
 * @data_sh: relevant
 * Return: 1 on success
 */
int prints_envir_var(data_shell *data_sh)
{
	int k, j;

	for (k = 0; data_sh->envir_var[k]; k++)
	{
		for (j = 0; data_sh->envir_var[k][j]; j++)
			;

		write(STDOUT_FILENO, data_sh->envir_var[k], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	data_sh->stat = 0;

	return (1);
}