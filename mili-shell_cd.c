#include "shell.h"

/**
 * change_dir_shell - a function that changes current directory
 * @data_sh: relevant data environment
 * Return: 1 on success
 */
int change_dir_shell(data_shell *data_sh)
{
	char *directory;
	int is_hme1, is_hme2, is_dble_dash;

	directory = data_sh->args[1];

	if (directory != NULL)
	{
		is_hme1 = _strgcmp("$HOME", directory);
		is_hme2 = _strgcmp("~", directory);
		is_dble_dash = _strgcmp("--", directory);
	}

	if (directory == NULL || !is_hme1 || !is_hme2 || !is_dble_dash)
	{
		change_to_home_dir(data_sh);
		return (1);
	}

	if (_strgcmp("-", directory) == 0)
	{
		change_to_prev_dir(data_sh);
		return (1);
	}

	if (_strgcmp(".", directory) == 0 || _strgcmp("..", directory) == 0)
	{
		change_par_dir(data_sh);
		return (1);
	}
	change_dir(data_sh);

	return (1);
}