#include "sort.h"

/**
 * swapper - A helper function to swap two elements in the array.
 *
 * @a: First element.
 * @b: Second element.
 */

void swapper(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * print_array_section - A helper function to print a portion of the array.
 *
 * @array: The array to print.
 * @low: The starting index of the section.
 * @count: The number of elements in the section.
 */

void print_array_section(int *array, int low, int count)
{
	int i;
	for (i = low; i < low + count; i++)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * bitonic_merge - A function that merges and sorts a bitonic sequence.
 *
 * @array: Array to be sorted.
 * @low: Starting index of the sequence.
 * @count: Number of elements in the sequence.
 * @direction: Direction of sorting (1 for ascending, 0 for descending).
 */

void bitonic_merge(int *array, int low, int count, int direction)
{
	int i, mid = count / 2;

	if (count > 1)
	{
		for (i = low; i < low + mid; i++)
		{
			if (direction == (array[i] > array[i + mid]))
			{
				swapper(&array[i], &array[i + mid]);
			}
		}

		bitonic_merge(array, low, mid, direction);
		bitonic_merge(array, low + mid, mid, direction);
	}
}

/**
 * b_sort_recursive - A recursive function that builds a bitonic sequence.
 *
 * @array: Array to be sorted.
 * @low: Starting index of the sequence.
 * @count: Number of elements in the sequence.
 * @direction: Direction of sorting (1 for ascending, 0 for descending).
 */

void b_sort_recursive(int *array, int low, int count, int direction)
{
	if (count > 1)
	{
		int mid = count / 2;

		printf("Merging [%d/%d] (%s):\n", count, count, direction ? "UP" : "DOWN");
		print_array_section(array, low, count);

		b_sort_recursive(array, low, mid, 1);

		b_sort_recursive(array, low + mid, mid, 0);

		bitonic_merge(array, low, count, direction);

		printf("Result [%d/%d] (%s):\n", count, count, direction ? "UP" : "DOWN");
		print_array_section(array, low, count);
	}
}

/**
 * bitonic_sort - A function that sorts an array of integers in
 * ascending order using Bitonic sort.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	b_sort_recursive(array, 0, size, 1);
}
