#include "sort.h"

/**
 * shell_sort - A function that sorts an array of integers
 * in ascending order using the Shell sort algorithm with
 * the Knuth sequence.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int s_temp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			s_temp = array[i];
			for (j = i; j >= gap && array[j - gap] > s_temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = s_temp;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
