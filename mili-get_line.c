#include "shell.h"

/**
 * assigns_line - a function that assigns the line variable for get_line
 * @line_ptr: Buffer that stores the input string
 * @size_ptr: Size of line buffer
 * @input_str: String that is used to assign to line
 * @str_size: Size of the input string
 */
void assigns_line(char **line_ptr, size_t *size_ptr, char *input_s, size_t s_size)
{
    if (*line_ptr == NULL)
    {
        if (s_size > BUFSIZE)
            *size_ptr = s_size;
        else
            *size_ptr = BUFSIZE;
        *line_ptr = input_s;
    }
    else if (*size_ptr < s_size)
    {
        if (s_size > BUFSIZE)
            *size_ptr = s_size;
        else
            *size_ptr = BUFSIZE;
        *line_ptr = input_s;
    }
    else
    {
        _strgcpy(*line_ptr, input_s);
        free(input_s);
    }
}

/**
 * getline_fn - a function that reads data input from stream
 * @line_ptr: buffer that stores the input
 * @size_ptr: size of lineptr
 * @input_strm: stream to read data input from
 * Return: number of bytes
 */
ssize_t getline_fn(char **line_ptr, size_t *size_ptr, FILE *input_strm)
{
	int k;
	static ssize_t d_input;
	ssize_t rtn_val;
	char *input_buffer;
	char curr_char = 'z';

    if (d_input == 0)
        fflush(input_strm);
    else
        return (-1);
    d_input = 0;

    input_buffer = malloc(sizeof(char) * BUFSIZE);
    if (input_buffer == NULL)
        return (-1);

    while (curr_char != '\n')
    {
        k = read(STDIN_FILENO, &curr_char, 1);

        if (k == -1 || (k == 0 && d_input == 0))
        {
            free(input_buffer);
            return (-1);
        }

        if (k == 0 && d_input != 0)
        {
            d_input++;
            break;
        }

        if (d_input >= BUFSIZE)
            input_buffer = mili_realloc(input_buffer, d_input, d_input + 1);

        input_buffer[d_input] = curr_char;
        d_input++;
    }

    input_buffer[d_input] = '\0';
    assigns_line(line_ptr, size_ptr, input_buffer, d_input);
    rtn_val = d_input;

    if (k != 0)
        d_input = 0;

    return (rtn_val);
}
