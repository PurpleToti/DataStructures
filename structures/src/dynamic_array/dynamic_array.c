#include "dynamic_array.h"

#include <stdlib.h>
#include <memory.h>

typedef struct _DynamicArray
{
	unsigned int size;
	unsigned int length;
	unsigned int max_length;
	void* data;
	float ratio;
} DynamicArray;

void* default_dynamic_array_malloc(size_t size)
{
	void* block = malloc(size);
	return block;
}

void default_dynamic_array_free(void* block)
{
	if (!block) return;
	free(block);
}

void* (*dynamic_array_malloc)(size_t size) = default_dynamic_array_malloc;
void (*dynamic_array_free)(void* block) = default_dynamic_array_free;

void dynamic_array_set_malloc(void* (*new_dynamic_array_malloc)(size_t size))
{
	dynamic_array_malloc = new_dynamic_array_malloc;
}

void dynamic_array_set_free(void (*new_dynamic_array_free)(void* block))
{
	dynamic_array_free = new_dynamic_array_free;
}

void dynamic_array_destroy_data(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return;
	if (!(dynamic_array->data)) return;

	dynamic_array_free(dynamic_array->data);
}

void dynamic_array_destroy(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return;
	dynamic_array_destroy_data(dynamic_array);
	dynamic_array_free(dynamic_array);
}

DynamicArray* dynamic_array_allocate_data(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return NULL;

	dynamic_array->data = dynamic_array_malloc(dynamic_array->max_length * dynamic_array->size);

	return dynamic_array;
}

DynamicArray* dynamic_array_update_max_length(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return NULL;

	if ((dynamic_array->max_length - dynamic_array->length) > 1) return dynamic_array;

	dynamic_array->max_length = (int)(dynamic_array->length * dynamic_array->ratio) + 1;

	return dynamic_array;
}

DynamicArray* dynamic_array_reallocate_data(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return NULL;

	void* old_data = dynamic_array->data;
	unsigned int old_max_length = dynamic_array->max_length;
	
	dynamic_array = dynamic_array_update_max_length(dynamic_array);
	dynamic_array->data = dynamic_array_malloc(dynamic_array->max_length * dynamic_array->size);
	memcpy(dynamic_array->data, old_data, (size_t)(old_max_length * dynamic_array->size));
	free(old_data);

	return dynamic_array;
}

DynamicArray* dynamic_array_create(void)
{
	DynamicArray* dynamic_array = dynamic_array_malloc(sizeof(DynamicArray));
	if (!dynamic_array) return NULL;

	dynamic_array->size = 0;
	dynamic_array->length = 0;
	dynamic_array->ratio = .0f;
	dynamic_array->data = NULL;

	return dynamic_array;
}

DynamicArray* dynamic_array_create_full(unsigned int size, unsigned int length, float ratio)
{
	DynamicArray* dynamic_array = dynamic_array_create();
	dynamic_array->size = size;
	dynamic_array->length = length;
	dynamic_array->ratio = ratio;

	dynamic_array = dynamic_array_update_max_length(dynamic_array);

	dynamic_array = dynamic_array_allocate_data(dynamic_array);

	return dynamic_array;
}

DynamicArray* dynamic_array_resize(DynamicArray* dynamic_array, unsigned int new_length)
{
	if (!dynamic_array) return NULL;

	dynamic_array->length = new_length;

	dynamic_array = dynamic_array_reallocate_data(dynamic_array);

	return dynamic_array;
}

void* dynamic_array_get_data(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return NULL;

	return dynamic_array->data;
}

unsigned int dynamic_array_get_size(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return 0;

	return dynamic_array->size;
}

unsigned int dynamic_array_get_length(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return 0;

	return dynamic_array->length;
}

float dynamic_array_get_ratio(DynamicArray* dynamic_array)
{
	if (!dynamic_array) return 0;

	return dynamic_array->ratio;
}