#include "shell.h"

/**
 * bfree - It will free a pointer and NULLs the address
 * @ptr: pointer address to free
 *
 * Return: 1 if freed, else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
