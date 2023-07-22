#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *swap_node(listint_t *node, listint_t **list);

/* 2-selection_sort.c */
void selection_sort(int *array, size_t size);
void swap_two_ints(int *a, int *b);


/* 3-quick_sort.c */
void quick_sort(int *array, size_t size);
void swap_int(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);

/* 100-shell_sort.c */
void swap(int *array, int item1, int item2);
void shell_sort(int *array, size_t size);

/* 101-cocktail_sort_list.c */
void swap1(listint_t **list, listint_t *head, listint_t *aux);
void swap1(listint_t **list, listint_t *head, listint_t *aux);
void cocktail_sort_list(listint_t **list);

/* 102-counting_sort.c */
void counting_sort(int *array, size_t size);



#endif /* SORT_H */
