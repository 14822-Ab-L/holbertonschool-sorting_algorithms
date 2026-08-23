#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;
	int temp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;

		while (j < size)
		{
			if (array[j] < array[min])
				min = j;

			j++;
		}

		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;

			print_array(array, size);
		}

		i++;
	}
}
