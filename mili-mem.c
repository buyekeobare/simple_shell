#include "shell.h"

/**
 * mili_memcpy - Copies information
 * @dest_ptr: destination pointer
 * @src_ptr: source pointer
 * @n: size of new pointer
 * Return: 0
 */
void mili_memcpy(void *dest_ptr, const void *src_ptr, unsigned int n)

{
	char *char_src_ptr = (char *)src_ptr;
	char *char_dest_ptr = (char *)dest_ptr;
	unsigned int x;

	for (x = 0; x < n; x++)
		char_dest_ptr[x] = char_src_ptr[x];
}

/**
 * mili_realloc - It reallocates memory block
 * @org_ptr: pointer to memory previously allocated
 * @ol_size: size of allocated space of org_ptr
 * @nw_size: new size of new memory block
 * Return: orig_ptr
 * if nw_size == ol_size return org_ptr without changes
 * if malloc fails return NULL
 */
void *mili_realloc(void *org_ptr, unsigned int ol_size, unsigned int nw_size)

{
	void *nw_ptr;

	if (org_ptr == NULL)
		return (malloc(nw_size));

	if (nw_size == 0)
	{
		free(org_ptr);
		return (NULL);
	}

	if (nw_size == ol_size)
		return (org_ptr);

	nw_ptr = malloc(nw_size);
	if (nw_ptr == NULL)
		return (NULL);

	if (nw_size < ol_size)
		mili_memcpy(nw_ptr, org_ptr, nw_size);
	else
		mili_memcpy(nw_ptr, org_ptr, ol_size);

	free(org_ptr);
	return (nw_ptr);
}

/**
 * mili_realloc_dp - It reallocates memory block of double pointer
 * @ptr: double pointer to memory prev allocated
 * @ol_size: size of the allocated space of ptr
 * @nw_size: new size of the new memory block
 * Return: ptr
 * if nw_size == ol_size, return ptr witht changes
 * if malloc fails, return NULL
 */
char **mili_realloc_dp(char **org_ptr, unsigned int ol_size, unsigned int nw_size)
{
	char **nw_ptr;
	unsigned int x;

	if (org_ptr == NULL)
		return (malloc(sizeof(char *) * nw_size));

	if (nw_size == ol_size)
		return (org_ptr);

	nw_ptr = malloc(sizeof(char *) * nw_size);
	if (nw_ptr == NULL)
		return (NULL);

	for (x = 0; x < ol_size; x++)
		nw_ptr[x] = org_ptr[x];

	free(org_ptr);

	return (nw_ptr);
}
