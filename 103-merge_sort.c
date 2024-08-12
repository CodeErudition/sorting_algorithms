#include "sort.h"

/**
 * print_subarray - Prints a sub-array
 * @array: The array to be printed
 * @start: Start index of the sub-array
 * @end: End index of the sub-array
 */

void print_subarray(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * merger - A function that merges two sub-arrays of array[].
 * First sub-array is array[left..middle]
 * Second sub-array is array[middle+1..right]
 *
 * @array: The array to be sorted
 * @left: Left index of the sub-array to be sorted
 * @middle: Middle index of the sub-array to be sorted
 * @right: Right index of the sub-array to be sorted
 * @m_temp: Temporary array for merging
 */

void merger(int *array, int left, int middle, int right, int *m_temp)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_subarray(array, left, middle);
	printf("[right]: ");
	print_subarray(array, middle + 1, right);

	i = left;
	j = middle + 1;
	k = left;

	while (i <= middle && j <= right)
	{
		if (array[i] <= array[j])
		{
			m_temp[k] = array[i];
			i++;
		}
		else
		{
			m_temp[k] = array[j];
			j++;
		}
		k++;
	}

	while (i <= middle)
	{
		m_temp[k] = array[i];
		i++;
		k++;
	}

	while (j <= right)
	{
		m_temp[k] = array[j];
		j++;
		k++;
	}

	for (i = left; i <= right; i++)
	{
		array[i] = m_temp[i];
	}

	printf("[Done]: ");
	print_subarray(array, left, right);
}

/**
 * m_sort_recursive - A function that implements the recursive
 * part of merge sort
 *
 * @array: The array to be sorted
 * @left: Left index of the sub-array to be sorted
 * @right: Right index of the sub-array to be sorted
 * @m_temp: Temporary array for merging
 */

void m_sort_recursive(int *array, int left, int right, int *m_temp)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		m_sort_recursive(array, left, middle, m_temp);
		m_sort_recursive(array, middle + 1, right, m_temp);

		merger(array, left, middle, right, m_temp);
	}
}

/**
 * merge_sort - A function that sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *m_temp;

	if (array == NULL || size < 2)
		return;

	m_temp = malloc(sizeof(int) * size);
	if (m_temp == NULL)
		return;

	m_sort_recursive(array, 0, size - 1, m_temp);

	free(m_temp);
}
