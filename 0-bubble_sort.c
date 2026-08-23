#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: number of elements in the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		j = 0;

		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
			j++;
		}

		i++;
	}
}
