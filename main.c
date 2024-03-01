#include "shell.h"

/**
 * data_free - Function that frees data structure
 * @data_sh: (structure) relevant data
 */
void data_free(data_shell *data_sh)
{
    unsigned int a;

    for (a = 0; data_sh->env_var[a]; a++)
    {
        free(data_sh->env_var[a]);
    }

    free(data_sh->env_var);
    free(data_sh->pid);
}

/**
 * init_data - Function that initializes data structure
 * @data_sh: (structure) relevant data
 * @argv: argument vector
 */
void init_data(data_shell *data_sh, char **argv)
{
    unsigned int a;
    char **environ_copy = environ;  // assuming environ is declared somewhere

    for (a = 0; environ_copy[a]; a++)
        ;

    data_sh->env_var = malloc(sizeof(char *) * (a + 1));

    for (a = 0; environ_copy[a]; a++)
    {
        data_sh->env_var[a] = _strgdup(environ_copy[a]);
    }

    data_sh->env_var[a] = NULL;
    data_sh->pid = mili_itoa(getppid());
}

/**
 * main - entry point.
 * @argc: argument count.
 * @argv: argument vector.
 */
int main(int argc, char **argv)
{
    data_shell data_sh;
    (void)argc;

    signal(SIGINT, handleCrtl_c);
    init_data(&data_sh, argv);
    shellLoop(&data_sh);
    data_free(&data_sh);

    if (data_sh.stat < 0)
        return 255;

    return data_sh.stat;
}
