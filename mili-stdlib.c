#include "shell.h"

/**
 * getLength - function that gets the lenghth of a number
 * @num: type is interger number
 * Return: length
 */
int getLength(int num)
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
 * @num: type is interger number
 * Return: string
 */
char *mili_itoa(int num)
{
	unsigned int nm;
	int len = getLength(num);
	char *buffer;

	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == 0)
		return (NULL);
	*(buffer + len) = '\0';

	if (num < 0)
	{
		nm = num * -1;
		buffer[0] = '-';
	}
	else
	{
		nm = num;
	}

	len--;
	do {
		*(buffer + len) = (nm % 10) + '0';
		nm = nm / 10;
		len--;
	}
	while (nm > 0)
		;
	return (buffer);
}

/**
 * mili_atoi - converts a string to an integer
 * @s: string input parameter
 * Return: converted integer from string
 */

int mili_atoi(char *s)
{
	unsigned int result = 0, n = 0, x = 0, m = 1, z = 1, i;

	while (*(s + result) != '\0')
	{
		if (n > 0 && (*(s + result) < '0' || *(s + result) > '9'))
			break;

		if (*(s + result) == '-')
			m *= -1;

		if ((*(s + result) >= '0') && (*(s + result) <= '9'))
		{
			if (n > 0)
				z *= 10;
			n++;
		}
		result++;
	}

	for (i = result - n; i < result; i++)
	{
		x = x + ((*(s + i) - 48) * z);
		z /= 10;
	}
	return (x * m);
}

