#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
static void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions an array using Lomuto scheme
 * @array: array of integers
 * @size: size of the array
 * @low: lower index
 * @high: higher index
 *
 * Return: index of the pivot
 */
static int partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low;

	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
		j++;
	}

	if (array[i] != array[high])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - recursively sorts an array
 * @array: array of integers
 * @size: size of the array
 * @low: lower index
 * @high: higher index
 */
static void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low >= high)
		return;

	pivot_index = partition(array, size, low, high);

	quick_sort_recursive(array, size, low, pivot_index - 1);
	quick_sort_recursive(array, size, pivot_index + 1, high);
}

/**
 * quick_sort - sorts an array using Quick sort
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, (int)size - 1);
}
