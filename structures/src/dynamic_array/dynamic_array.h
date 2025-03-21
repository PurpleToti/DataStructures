#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>

typedef struct _DynamicArray DynamicArray;

void dynamic_array_set_malloc(void* (*new_dynamic_array_malloc)(size_t size));

void dynamic_array_set_free(void (*new_dynamic_array_free)(void* block));

extern DynamicArray* dynamic_array_create(void);

extern void dynamic_array_destroy(DynamicArray* dynamic_array);

extern DynamicArray* dynamic_array_create_full(unsigned int size, unsigned int length, float ratio);

extern void* dynamic_array_get_data(DynamicArray* dynamic_array);

extern unsigned int dynamic_array_get_size(DynamicArray* dynamic_array);

extern unsigned int dynamic_array_get_length(DynamicArray* dynamic_array);

DynamicArray* dynamic_array_resize(DynamicArray* dynamic_array, unsigned int new_length);

#endif // DYNAMIC_ARRAY_H