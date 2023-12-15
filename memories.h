#ifndef MEMORIES_H
#define MEMORIES_H

#include <stdlib.h>


/* memories.c */
void *reallocate(void *pointer, size_t size_old, size_t size_new);

/* free.c */
void free_ptr(void *pointer);
void free_double_ptr(void **pointer);

#endif
