#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers
 * in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int b_temp, b_swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		b_swapped = 0;
		for (j = 1; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				b_temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = b_temp;
				print_array(array, size);
				b_swapped = 1;
			}
		}
		if (!b_swapped)
			break;
	}
}
