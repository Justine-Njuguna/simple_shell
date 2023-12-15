#include "memories.h"
#include <string.h>
/**
 * reallocate - Reallocates a mem block using malloc and free
 * @pointer: Ptr to the previously allocated memory
 * @size_old: size for ptr allocated space
 * @size_new: new size for memory block
 *
 * Return: Memory reallocated.
 */

void *reallocate(void *pointer, size_t size_old, size_t size_new)
{
	char *t, *auxiliary;

	if (size_new == size_old)
		return (pointer);

	if (pointer == NULL)
	{
		t = malloc(size_new);
		if (t == NULL)
			return (NULL);

		return (t);
	}

	if (size_new == 0 && pointer != NULL)
	{
		free(pointer);
		return (NULL);
	}

	t = malloc(size_new);
	if (t == NULL)
		return (NULL);

	auxiliary = pointer;
	memcpy(t, auxiliary, (size_old < size_new) ? size_old : size_new);
	free(pointer);

	return (t);
}
