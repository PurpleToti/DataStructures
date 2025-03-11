#include <stdio.h>

#include "../structure/array.h"

int main(void)
{
	Array* a = array_create_full(sizeof(int), 5);
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



	exit(0);
}