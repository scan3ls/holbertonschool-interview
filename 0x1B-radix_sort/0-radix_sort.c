#include "sort.h"
#include <stdio.h>

/**
 * radix_sort - radix sort using least significant figures
 *@array: array of ints to sort
 *@size: size of array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int *copy_arr = malloc(sizeof(int) * size);
	int i, num, c;
	int significant_figure = 1, sorting = 1;

	if (size == 1)
	{
		free(copy_arr);
		return;
	}

	while (sorting)
	{
		sorting = 0;
		c = 0;
		for (num = 0; num <= 9; num++)
		{
			for (i = 0; i < (int)size; i++)
			{
				if ((array[i] / significant_figure) % 10 == num)
				{
					if (num != 0 && (array[i] / significant_figure) % 10)
						sorting = 1;
					copy_arr[c++] = array[i];
				}
			}
		}
		significant_figure *= 10;
		copy(copy_arr, array, size);
		if (sorting)
			print_array(array, size);
	}

	free(copy_arr);
}

/**
 * copy - copy array into a copy dest
 *@array: array to copy
 *@copy_arr: dest of copy
 *@size: size of both arrays
 * Return: void
 */
void copy(int *array, int *copy_arr, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		copy_arr[i] = array[i];
}
