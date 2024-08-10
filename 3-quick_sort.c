#include "sort.h"

/**
 * swapper - A helper function that swaps two elements
 * in an array.
 *
 * @a: First element to swap.
 * @b: Second element to swap.
 */

void swapper(int *a, int *b)
{
	int q_temp = *a;
	*a = *b;
	*b = q_temp;
}

/**
 * partition - A function that partitions the array
 * using the Lomuto scheme.
 *
 * @array: The array to partition.
 * @lo: The lower index of the partition.
 * @hi: The higher index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot after partitioning.
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swapper(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[hi] < array[i + 1])
	{
		swapper(&array[i + 1], &array[hi]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * q_sort_recursive - A function that recursively sorts the
 * array using quicksort.
 *
 * @array: The array to sort.
 * @lo: The lower index of the partition.
 * @hi: The higher index of the partition.
 * @size: The size of the array.
 */

void q_sort_recursive(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int pi = partition(array, lo, hi, size);

		q_sort_recursive(array, lo, pi - 1, size);
		q_sort_recursive(array, pi + 1, hi, size);
	}
}

/**
 * quick_sort - A function that sorts an array of integers in
 * ascending order using Quick sort.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort_recursive(array, 0, size - 1, size);
}
