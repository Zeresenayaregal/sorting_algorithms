#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include "sort.h"

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer  stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Prototypes for mandatory ones */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
size_t part(int array[], size_t size);
void ob_sort(int array[], size_t size, int strt);

/* Prototypes for advanced ones */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);


/* Prototypes for print funcs */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* Prototypes for helper funcs */
void swp(int *num1, int *num2);
void heapify(int *array, int ed, int strt, size_t size);

#endif /* SORT_H */
