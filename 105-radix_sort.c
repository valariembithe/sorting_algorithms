#include "sort.h"
/**
 * max_val - gets max value from array
 * @array: pointer to array
 * @size: size of the array
 * Return: max value from array
 */
int max_val(int *array, size_t size)
{
	int max = array[0];
	size_t j;

	for (j = 0; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	return (max);
}
/**
 * radix_sort - sorts an array of integers is ASC
 * order implementing Radix Sort algorithm
 * @array: pointer to array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *new_array;
	int j, max, e = 1;
	int size_init = size;

	if (!array || size < 2)
		return;

	max = max_val(array, size);

	new_array = malloc(sizeof(int) * size);
	while (max / e > 0)
	{
		int brews[20] = {0};

		j = 0;

		while (j < size_init)
		{
			brews[(array[j] / e) % 10]++;
			j++;
		}

		if (brews != NULL)
		{
			for (j = 1; j < 10; j++)
				brews[j] += brews[j - 1];

			for (j = size_init - 1; j >= 0; j--)
			{
				new_array[brews[(array[j] / e) % 10] - 1] = array[j];
				brews[(array[j] / e) % 10]--;
			}

			for (j = 0; j < size_init; j++)
				array[j] = new_array[j];
		}
		e *= 10;
		print_array(array, size);
	}
	free(new_array);
}
