#include "shell.h"

/**
 * read_input - A fucntion that reads the input string
 * @result: it returns the value of getline function
 * Return: input string.
 */
char *read_input(int *result)
{
	char *inp_str = NULL;
	size_t buffer_size = 0;

	*result = getline_fn(&inp_str, &buffer_size, stdin);

	return (inp_str);
}
