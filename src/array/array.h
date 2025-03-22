#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct _Array Array;

void set_array_malloc(void* (*new_array_malloc)(size_t size));

void set_array_free(void (*new_array_free)(void* block));

extern Array* array_create();

extern void array_destroy(Array* array);

extern Array* array_create_full(unsigned int size, unsigned int length);

extern void* array_get_data(Array* array);

extern unsigned int array_get_size(Array* array);

extern unsigned int array_get_length(Array* array);

#endif // ARRAY_H