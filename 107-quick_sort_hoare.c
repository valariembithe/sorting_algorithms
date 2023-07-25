#include <stdio.h>
#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the Quick sort algorithm with Hoare partition scheme.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare_recursive(array, 0, size - 1);
}

/**
 * quicksort_hoare_recursive - Recursive function to perform Quick sort.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 */
void quicksort_hoare_recursive(int *array, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		ssize_t pivot = hoare_partition(array, low, high);

		print_array(array + low, high - low + 1);

		quicksort_hoare_recursive(array, low, pivot);
		quicksort_hoare_recursive(array, pivot + 1, high);
	}
}

/**
 * hoare_partition - Partition function for Quick sort (Hoare scheme).
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The index of the pivot element after partitioning.
 */
ssize_t hoare_partition(int *array, ssize_t low, ssize_t high)
{
	int pivot = array[high];
	ssize_t i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return j;

		swap_(&array[i], &array[j]);
	}
}

/**
 * swap_ - Swaps two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_(int *a, int *b)
{
	if (a != b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;

		printf("Swap: %d, %d\n", *a, *b);
		print_array(a, 2);
	}
}
