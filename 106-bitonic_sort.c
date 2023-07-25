#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @array: The array.
 * @i: The index of the first element.
 * @j: The index of the second element.
 */
void swap(int *array, int i, int j)
{
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        printf("Result [%d/%d] (%s):\n", j - i + 1, j + 1,
	      (array[i] < array[j]) ? "UP" : "DOWN");
        print_array(array + i, j - i + 1);
}

/**
 * bitonic_compare - Compares and swaps two elements in a bitonic sequence.
 * @array: The array.
 * @size: The size of the array.
 * @dir: The direction of comparison (1 for ascending, 0 for descending).
 */
void bitonic_compare(int *array, size_t size, int dir)
{
        size_t dist = size / 2;
        size_t i;

        for (i = 0; i < dist; i++)
        {
                if ((array[i] > array[i + dist]) == dir)
                        swap(array, i, i + dist);
        }
}

/**
 * bitonic_merge - Recursively merges two bitonic sequences.
 * @array: The array.
 * @size: The size of the array.
 * @dir: The direction of comparison (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, int dir)
{
        if (size > 1)
        {
                size_t mid = size / 2;

                printf("Merging [%lu/%lu] (%s):\n", size,
		       size, (dir) ? "UP" : "DOWN");
                print_array(array, size);

                bitonic_compare(array, mid, dir);
                bitonic_merge(array, mid, dir);
                bitonic_merge(array + mid, mid, dir);
        }
}

/**
 * bitonic_sort - Sorts an array in ascending order using Bitonic sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
        if (array == NULL || size < 2 || (size & (size - 1)) != 0)
                return;

        printf("Merging [1/%lu] (UP):\n", size);
        print_array(array, 1);

        bitonic_merge(array, size, 1);
}
