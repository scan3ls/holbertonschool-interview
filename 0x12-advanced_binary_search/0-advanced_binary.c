#include "search_algos.h"

/**
 * advanced_binary - driver for searching an array
 *                   using the search function
 *@array: array of integers
 *@size: length of array
 *@value: target value to find
 * Return: index of target value in array or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int found = search(array, size, value);

	return ((found >= 0) ? found : -1);
}

/**
 * search - recursive function to search array
 *          for a specific integer
 *@array: array of integers
 *@size: length of array
 *@value: target value to find
 * Return: index of target value in array
 */
int search(int *array, size_t size, int value)
{
	int *step, index = 0;
	int half = (float)size / 2.0 + 0.5;

	print_array(array, size);
	if (*array == value)
		return (index);

	if (size < 2 && *array != value)
		return (INT_MIN);

	step = array + (half);

	if (value == *(step - 1))
		return (search(array, half, value));

	if (value >= *step)
		return (search(step, size - half, value) + half);
	return (search(array, half, value));
}

/**
 * print_array - Print an array of integers
 *@array: array of integers
 *@size: length of array
 */
void print_array(int *array, size_t size)
{
	int i;

	printf("Searching in array: ");
	for (i = 0; i < (int)size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}
