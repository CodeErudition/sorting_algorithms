#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int s_temp;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			s_temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = s_temp;
			print_array(array, size);
		}
	}
}
