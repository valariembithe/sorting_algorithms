#include "sort.h"

/**
 * swap_two_ints - Swaps two integers using pointers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_two_ints(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array in ascending order using Selection sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			swap_two_ints(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
