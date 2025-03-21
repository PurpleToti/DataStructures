#include <stdio.h>

#include "../array/array.h"

void* my_array_malloc(size_t size)
{
	printf("My Malloc! : with size %d\n", (int) size);
	void* block = malloc(size);
	return block;
}

void my_array_free(void* block)
{
	printf("My Free!\n");
	free(block);
}

void* memory;

int main(void)
{
	memory = malloc(1000);

	set_array_malloc(my_array_malloc);
	set_array_free(my_array_free);

	Array* a = array_create_full(sizeof(int), 9);
	unsigned int size = array_get_size(a);
	unsigned int length = array_get_length(a);

	printf("size : %d; length : %d\n", size, length);

	int* data = array_get_data(a);
	for (int i = 0; i < length; i++)
	{
		data[i] = i;
	}

	for (int i = 0; i < length; i++)
	{
		printf("%d : %d\n", i, data[i]);
	}

	array_destroy(a);

	exit(0);
}