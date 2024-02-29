#include "shell.h"

/**
 * mem_cpy - Copies information
 * @nwptr: destination pointer
 * @ptr: source pointer
 * @n: size of new pointer
 * Return: 0
 */
void mem_cpy(void *nwptr, const void *ptr, unsigned int n)

{
	char *char_ptr = (char *)ptr;
	char *char_nwptr = (char *)nwptr;
	unsigned int x;

	for (x = 0; x < size; x++)
		char_nwptr[x] = char_ptr[x];
}

/**
 * re_allocate - It reallocates memory block
 * @ptr: pointer to memory previously allocated
 * @ol_size: size of alloc space of ptr
 * @nw_size: new size of new memory block
 * Return: ptr
 * if nw_size == ol_size return ptr witht changes
 * if malloc fails return NULL
 */
void *re_allocate(void *ptr, unsigned int ol_size, unsigned int nw_size)

{
	void *nwptr;

	if (ptr == NULL)
		return (malloc(nw_size));

	if (nw_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (nw_size == ol_size)
		return (ptr);

	nwptr = malloc(nw_size);
	if (nwptr == NULL)
		return (NULL);

	if (nw_size < ol_size)
		mem_cpy(nwptr, ptr, nw_size);
	else
		mem_cpy(nwptr, ptr, ol_size);

	free(ptr);
	return (nwptr);
}

/**
 * re_allocatedp - It reallocates memory block of double pointer
 * @ptr: double pointer to memory prev allocated
 * @ol_size: size of the allocated space of ptr
 * @nw_size: new size of the new memory block
 * Return: ptr
 * if nw_size == ol_size, return ptr witht changes
 * if malloc fails, return NULL
 */
char **re_allocatedp(char **ptr, unsigned int ol_size, unsigned int nw_size)
{
	char **nwptr;
	unsigned int x;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * nw_size));

	if (nw_size == ol_size)
		return (ptr);

	nwptr = malloc(sizeof(char *) * nw_size);
	if (nwptr == NULL)
		return (NULL);

	for (x = 0; x < old_size; x++)
		nwptr[x] = ptr[x];

	free(ptr);

	return (nwptr);
}