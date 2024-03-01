#include "shell.h"

/**
 * take_line - a function that assigns the line 
 * variable for get line
 * @line_ptr: Buffer that store input string
 * @buffer: string that is been called to line
 * @n: size of line
 * @k: size of buffer
 */
void take_line(char **line_ptr, size_t *n, char *buffer, size_t k)
{

	if (*line_ptr == NULL)
	{
		if  (k > BUFSIZE)
			*n = k;

		else
			*n = BUFSIZE;
		*line_ptr = buffer;
	}
	else if (*n < k)
	{
		if (k > BUFSIZE)
			*n = k;
		else
			*n = BUFSIZE;
		*line_ptr = buffer;
	}
	else
	{
		_strgcpy(*line_ptr, buffer);
		free(buffer);
	}
}

/**
 * getline_fn - a function that reads data input from stream
 * @line_ptr: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read data input from
 * Return: number of bytes
 */
ssize_t getline_fn(char **line_ptr, size_t *n, FILE *stream)
{
	int k;
	static ssize_t d_input;
	ssize_t rtn_val;
	char *buffer;
	char t = 'z';
	
		return (-1);
	while (t != '\n')
	{
		k = read(STDIN_FILENO, &t, 1);
		if (k == -1 || (a == 0 && d_input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (k == 0 && d_input != 0)
		{
			d_input++;
			break;
		}
		if (d_input >= BUFSIZE)
			buffer = re_allocate(buffer, d_input, d_input + 1);
		buffer[d_input] = t;
		d_input++;
	}
	buffer[d_input] = '\0';
	getline_fn(line_ptr, n, buffer, d_input);
	rtn_val = d_input;
	if (k != 0)
		d_input = 0;
	return (rtn_val);
}
