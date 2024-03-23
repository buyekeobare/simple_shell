#include "shell.h"

/**
 * _getbuiltin - get built-in function
 * @parm: Pointer to the data_shell struct containing command parameters
 *
 * Description: Searches for a built-in function based on the first argument
 * in the data_shell struct.
 * Return: Function pointer to the built-in function. NULL if not found.
 */
int (*_getbuiltin(char *parm))(data_shell *)
{
        builtin_t builtin[] = {
                { "env", prints_envir_var },
                { "exit", _exitshell },
                { "setenv", _setEnv },
                { "unsetenv", _unsetEnv },
                { "cd", change_dir_shell },
                { "help", _gethelp },
                { NULL, NULL }
        };
        int z;

        for (z = 0; builtin[z].cmd_name; z++)
        {
                if (_strgcmp(builtin[z].cmd_name, parm) == 0)
                        break;
        }

        return (builtin[z].mili_function);

}
