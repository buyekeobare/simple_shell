#include "shell.h"

/**
 * cmp_envir_nm - a function that compares environment 
 * variables' names with the name passed
 * @nenvir: name of the environment variable
 * @nm: name passed
 * Return: 0 if are not equal, another value if otherwise
 */
int cmp_envir_nm(const char *nenvir, const char *nm)
{
	int j;

	for (j = 0; nenvir[j] != '='; j++)
	{
		if (nenvir[j] != nm[j])
		{
			return (0);
		}
	}

	return (j + 1);
}
/**
 * get_envir - function that gets an environment variable
 * @nenvir: name of the environment variable
 * @env_var: environment variable
 * Return: value of the environment variable if found,
 * otherwise return NULL
 */
char *get_envir(const char *nenvir, char **env_var)
{
	char *p_env;
	int i, mv;

	/* initialize p_env value */
	p_env = NULL;
	mv = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; env_var[i]; i++)
	{
		/* If name & envir are equal */
		mv = cmp_envir_nm(env_var[i], nenvir);
		if (mv)
		{
			p_env = env_var[i];
			break;
		}
	}

	return (p_env + mv);
}
/**
 * envir - function that prints the environment variables
 * @data_sh: relevant
 * Return: 1 on success
 */
int envir(data_shell *data_sh)
{
	int k, j;

	for (k = 0; data_sh->env_var[k]; k++)
	{
		for (j = 0; data_sh->env_var[k][j]; j++)
			;

		write(STDOUT_FILENO, data_sh->env_var[k], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	data_sh->stat = 0;

	return (1);
}