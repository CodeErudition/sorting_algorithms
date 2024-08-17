#include "sort.h"

/**
 * swapper - A helper function that swap two elements
 * in an array
 * @a: First element
 * @b: Second element
 */

void swapper(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - A function that sift down to maintain the
 * heap property
 *
 * @array: The array representing the heap
 * @start: The start index of the heap
 * @end: The end index of the heap
 * @size: Total size of the array (for printing)
 */

void sift_down(int *array, int start, int end, size_t size)
{
	int root = start;
	int child;
	int swap_idx;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
		{
			swap_idx = child;
		}

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
		{
			swap_idx = child + 1;
		}

		if (swap_idx == root)
		{
			return;
		}
		else
		{
			swapper(&array[root], &array[swap_idx]);
			print_array(array, size);
			root = swap_idx;
		}
	}
}

/**
 * he_ap - A function that Build the heap (rearrange the array
 * into a max heap)
 *
 * @array: The array to heapify
 * @size: The size of the array
 */

void he_ap(int *array, size_t size)
{
	int start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - A function that sort an array of integers in
 * ascending order using Heap sort
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */

void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	he_ap(array, size);

	end = size - 1;
	while (end > 0)
	{
		swapper(&array[end], &array[0]);
		print_array(array, size);

		end--;

		sift_down(array, 0, end, size);
	}
}
