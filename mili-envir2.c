#include "shell.h"

/**
 * cp_information - Function that copies information
 * to create a new environment or alias
 * @nm: name (environment or alias)
 * @val: value (environment or alias)
 * Return: new environment or alias
 */
char *cp_information(char *nm, char *val)
{
        char *new_info;
        int nameLen, valueLen, length;

        nameLen = _strglen(nm);
        valueLen = _strglen(val);
        length = nameLen + valueLen + 2;
        new_info = malloc(sizeof(char) * (length));
        _strgcpy(new_info, nm);
        _strgcat(new_info, "=");
        _strgcat(new_info, val);
        _strgcat(new_info, "\0");

        return (new_info);
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

        for (j = 0; data_sh->envir_var[j]; j++)
        {
                v_env = _strgdup(data_sh->envir_var[j]);
                n_env = _strgtok(v_env, "=");
                if (_strgcmp(n_env, nm) == 0)
                {
                        free(data_sh->envir_var[j]);
                        data_sh->envir_var[j] = cp_information(n_env, val);
                        free(v_env);
                        return;
                }
                free(v_env);
        }

        data_sh->envir_var= mili_realloc_dp(data_sh->envir_var, j, sizeof(char *) * (j + 2));
        data_sh->envir_var[j] = cp_information(nm, val);
        data_sh->envir_var[j + 1] = NULL;
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
                _geterror(data_sh, -1);
                return (1);
        }

        setEnv(data_sh->args[1], data_sh->args[2], data_sh);

        return (1);
}

/**
 * _unsetEnv - A function that deletes an
 * environment variable
 * @data_sh: relevant data
 * Return: 1 on success
 */
int _unsetEnv(data_shell *data_sh)
{
        char **realloc_env;
        char *v_env, *n_env;
        int j, p, q;

        if (data_sh->args[1] == NULL)
        {
                _geterror(data_sh, -1);
                return (1);
        }
        q = -1;
        for (j = 0; data_sh->envir_var[j]; j++)
        {
                v_env = _strgdup(data_sh->envir_var[j]);
                n_env = _strgtok(v_env, "=");
                if (_strgcmp(n_env, data_sh->args[1]) == 0)
                {
                        q = j;
                }
                free(v_env);
        }
        if (q == -1)
        {
                _geterror(data_sh, -1);
                return (1);
        }
        realloc_env = malloc(sizeof(char *) * (j));
        for (j = p = 0; data_sh->envir_var[j]; j++)
        {
                if (j != q)
                {
                        realloc_env[p] = data_sh->envir_var[j];
                        p++;
                }
        }
        realloc_env[p] = NULL;
        free(data_sh->envir_var[q]);
        free(data_sh->envir_var);
        data_sh->envir_var = realloc_env;
        return (1);
}

