#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct _Array Array;

extern void* array_malloc(size_t size);

extern void array_free(void* block);

extern Array* array_create();

extern Array* array_create_full(unsigned int size, unsigned int length);

void* array_get_data(Array* array);

unsigned int array_get_size(Array* array);

unsigned int array_get_length(Array* array);

extern void array_destroy(Array* array);

#endif // ARRAY_H