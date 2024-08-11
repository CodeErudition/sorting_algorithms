#include "sort.h"

/**
 * counting_sort - A function that sorts an array of integers in
 * ascending order using
 *
 * the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void counting_sort(int *array, size_t size);
void counting_sort(int *array, size_t size)
{
	int *array_count, *array_out;
	int max_value = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	array_count = malloc(sizeof(int) * (max_value + 1));
	if (array_count == NULL)
		return;
	for (i = 0; i <= (size_t)max_value; i++)
		array_count[i] = 0;

	for (i = 0; i < size; i++)
		array_count[array[i]]++;

	print_array(array_count, max_value + 1);

	for (i = 1; i <= (size_t)max_value; i++)
		array_count[i] += array_count[i - 1];

	array_out = malloc(sizeof(int) * size);
	if (array_out == NULL)
	{
		free(array_count);
		return;
	}

	for (i = size; i > 0; i--)
	{
		array_out[array_count[array[i - 1]] - 1] = array[i - 1];
		array_count[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = array_out[i];

	free(array_count);
	free(array_out);
}
