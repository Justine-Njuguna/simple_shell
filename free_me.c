#include "memories.h"

/**
 * free_ptr - Free a ptr
 * @pointer: ptr to free
 */

void free_ptr(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}

	pointer = NULL;
}

/**
 * free_double_ptr - free a double ptr
 * @pointer: ptr to free
 */

void free_double_ptr(void **pointer)
{
	void **temp;

	for (temp = pointer; *temp != NULL; temp++)
		free_ptr(*temp);

	free(pointer);
}
