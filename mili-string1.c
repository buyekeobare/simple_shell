#include "shell.h"

/**
 * _strglen - function that finds and returns 
 * the lenght of a string
 * @strg: pointer to the string characters
 * Return: 0
 */
int _strglen(const char *strg)
{
	int length;

	for (length = 0; strg[length] != 0; length++)
	{
	}
	return (length);
}

/**
 * _strgcat - function that concatenates two strings
 * @dest: Pointer to the destination of copied string
 * @src: Pointer to the source of string
 * Return: Pointer to the destination string
 */
char *_strgcat(char *dest, const char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
		;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}

	dest[a] = '\0';
	return (dest);
}
/**
 * _strgcpy - function that copies the string pointed to by source
 * @dest: Pointer to the destination of copied string
 * @src: Pointer to the source of string
 * Return: Pointer to the destination string
 */
char *_strgcpy(char *dest, char *src)
{
	size_t n;

	for (n = 0; src[n] != '\0'; n++)
	{
		dest[n] = src[n];
	}
	dest[n] = '\0';

	return (dest);
}
/**
 * _strgdup - function that duplicates a string
 * in a heap memory
 * @strg: the string to duplicate
 * Return: duplicated string
 */
char *_strgdup(const char *strg)
{
	char nw*;
	size_t length;

	length = _strglen(strg);
	nw = malloc(sizeof(char) * (length + 1));
	if (nw == NULL)
		return (NULL);
	mem_cpy(nw, strg, length + 1);
	return (nw);
}