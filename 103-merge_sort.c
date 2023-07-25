#include <stdio.h>
#include "sort.h"

/**
 * merge - Merge two sorted sub-arrays into a single sorted array.
 * @array: The original array.
 * @left: The left sub-array.
 * @left_size: The size of the left sub-array.
 * @right: The right sub-array.
 * @right_size: The size of the right sub-array.
 */
void merge(int *array, int *left, size_t left_size,
	   int *right, size_t right_size)
{
	size_t i, j, k;
	i = j = k = 0;

        while (i < left_size && j < right_size)
        {
                if (left[i] <= right[j])
                {
                        array[k] = left[i];
                        i++;
                }
                else
                {
                        array[k] = right[j];
                        j++;
                }
                k++;
        }

        while (i < left_size)
        {
                array[k] = left[i];
                i++;
                k++;
        }

        while (j < right_size)
        {
                array[k] = right[j];
                j++;
                k++;
        }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
        size_t mid, left_size, right_size, i;
        int *left, *right, *merged_array;

        if (size > 1)
        {
                mid = size / 2;
                left_size = mid;
                right_size = size - mid;
                left = array;
                right = array + mid;

                merge_sort(left, left_size);
                merge_sort(right, right_size);

                printf("Merging...\n[left]: ");
                for (i = 0; i < left_size; i++)
                {
                        printf("%d", left[i]);
                        if (i < left_size - 1)
                                printf(", ");
                }

                printf("\n[right]: ");
                for (i = 0; i < right_size; i++)
                {
                        printf("%d", right[i]);
                        if (i < right_size - 1)
                                printf(", ");
                }

                printf("\n");

                merged_array = malloc(size * sizeof(int));
                if (merged_array == NULL)
                        return;

                merge(merged_array, left, left_size, right, right_size);

                for (i = 0; i < size; i++)
                        array[i] = merged_array[i];
                printf("[Done]: ");

                for (i = 0; i < size; i++)
                {
                        printf("%d", array[i]);
                        if (i < size - 1)
                                printf(", ");
                }
                printf("\n");

                free(merged_array);
	}
}
