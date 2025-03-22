#include <stdio.h>

#include "../array/array.h"
#include "../dynamic_array/dynamic_array.h"

void* my_malloc(size_t size)
{
	printf("My alloc used : %d allocated\n", (int)size);
	return malloc(size);
}

void my_free(void* block)
{
	printf("My free used\n");
	free(block);
}

int main(void)
{
	dynamic_array_set_malloc(my_malloc);
	dynamic_array_set_free(my_free);

	DynamicArray* a = dynamic_array_create_full(sizeof(int), 10, 1.5);

	int* a_data = dynamic_array_get_data(a);
	int length = dynamic_array_get_length(a);
	printf("lenght %d\n", length);
	for (int i = 0; i < length; i++)
	{
		a_data[i] = 0;
	}

	a = dynamic_array_resize(a, 15);
	a_data = dynamic_array_get_data(a);
	length = dynamic_array_get_length(a);
	printf("lenght %d\n", length);
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", a_data[i]);
	}

	dynamic_array_destroy(a);
	return 0;
}