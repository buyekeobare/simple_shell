#include "shell.h"

/**
 * brings_length - function that gets the lenghth of a number
 * @num: type is integer number
 * Return: length of number
 */
int brings_length(int num)
{
	unsigned int nm;
	int len = 1;

	if (num < 0)
	{
		len++;
		nm = num * -1;
	}
	else
	{
		nm = num;
	}
	while (n1 > 9)
	{
		len++;
		nm = nm / 10;
	}

	return (len);
}
/**
 * mili_itoa - function that converts interger to a string
 * @num: integer to be converted
 * Return: string
 */
char *mili_itoa(int num)
{
	unsigned int nm;
	int len = brings_length(num);
	char *count;

	count = malloc(sizeof(char) * (len + 1));
	if (count == 0)
		return (NULL);
	*(count + len) = '\0';

	if (num < 0)
	{
		nm = num * -1;
		count[0] = '-';
	}
	else
	{
		nm = num;
	}

	len--;
	do {
		*(count + len) = (nm % 10) + '0';
		nm = nm / 10;
		len--;
	}
	while (nm > 0)
		;
	return (count);
}

/**
 * mili_atoi - converts a string to an integer
 * @str_input: string input parameter
 * Return: converted integer from string
 */

int mili_atoi(char *str_input)
{
	unsigned int index = 0, n = 0, x = 0, m = 1, z = 1, i;

	while (*(str_input + index) != '\0')
	{
		if (n > 0 && (*(str_input + index) < '0' || *(str_input + index) > '9'))
			break;

		if (*(str_input + index) == '-')
			m *= -1;

		if ((*(str_input + index) >= '0') && (*(str_input + index) <= '9'))
		{
			if (n > 0)
				z *= 10;
			n++;
		}
		index++;
	}

	for (i = index - n; i < index; i++)
	{
		x = x + ((*(str_input + i) - 48) * z);
		z /= 10;
	}
	return (x * m);
}

