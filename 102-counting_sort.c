#include "sort.h"

/**
 * counting_sort - Sorts an array in ascending order using Counting sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = array[0];
	size_t j, index = 0;
	int i, *counting_array;

	if (size <= 1)
		return;

	for (j = 1; j < size; j++)
	{
		if (array[j] > max_value)
			max_value = array[j];
	}

	counting_array = malloc((max_value + 1) * sizeof(int));
	if (!counting_array)
		return;

	for (i = 0; i <= max_value; i++)
	{
		counting_array[i] = 0;
	}

	for (j = 0; j < size; j++)
	{
		counting_array[array[j]]++;
	}

	for (i = 0; i <= max_value; i++)
	{
		while (counting_array[i] > 0)
		{
			array[index] = i;
			counting_array[i]--;
			index++;
		}
	}

	print_array(counting_array, max_value + 1);

	free(counting_array);
}
