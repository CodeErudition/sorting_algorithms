#include "sort.h"

/**
 * max_value - A helper function to get the maximum value
 * in the array
 *
 * @array: The array to find the maximum value
 * @size: The size of the array
 *
 * Return: The maximum value in the array
 */

int max_value(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * sort_count - A function that perform counting sort on
 * array based on digit
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The digit we are sorting by (1, 10, 100, ...)
 */

void sort_count(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - A function that sorts an array of integers in
 * ascending order using the LSD (Least Significant Digit)
 * radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = max_value(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		sort_count(array, size, exp);
}
