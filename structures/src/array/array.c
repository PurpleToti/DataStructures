#include "array.h"

typedef struct _Array
{
	unsigned int size;
	unsigned int length;
	void* data;
} Array;

void* default_array_malloc(size_t size)
{
	void* block = malloc(size);
	return block;
}

void default_array_free(void* block)
{
	if (!block) return;
	free(block);
}

void* (*array_malloc)(size_t size) = default_array_malloc;
void (*array_free)(void* block) = default_array_free;

void set_array_malloc(void* (*new_array_malloc)(size_t size))
{
	array_malloc = new_array_malloc;
}

void set_array_free(void (*new_array_free)(void* block))
{
	array_free = new_array_free;
}

Array* array_create()
{
	Array* array = array_malloc(sizeof(Array));
	if (!array) return NULL;

	array->size = 0;
	array->length = 0;
	array->data = NULL;
	return array;
}

Array* array_allocate_data(Array* array)
{
	if (!array) return NULL;

	array->data = array_malloc(array->size * array->length);
	return array;
}

Array* array_create_full(unsigned int size, unsigned int length)
{
	Array* array = array_create();
	array->size = size;
	array->length = length;
	array = array_allocate_data(array);
	return array;
}

void* array_get_data(Array* array)
{
	if (!array) return NULL;
	return array->data;
}

unsigned int array_get_size(Array* array)
{
    if (!array) return 0;
    return array->size;
}

unsigned int array_get_length(Array* array)
{
    if (!array) return 0;
    return array->length;
}

void array_destroy_data(Array* array)
{
	if (!array) return;
	if (!(array->data)) return;
	array_free(array->data);
}

void array_destroy(Array* array)
{
	if (!array) return;
	array_destroy_data(array);
	array_free(array);
}