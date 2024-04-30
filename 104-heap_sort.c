#include "sort.h"

/**
 * heap_sort - Sorting arr using heap sort algor
 * @array: arr to be sort
 * @size: Size of the arr
 * Return: 0
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (!array || size < 2)
		return;

	for (a = size / 2; a >= 0; a--)
		heapify(array, size, a, size);
	for (a = size - 1; a >= 0; a--)
	{
		swp(&array[a], &array[0]);
		if (a != 0)
			print_array(array, size);
		heapify(array, a, 0, size);
	}
}

/**
 * heapify - Recursive function to sort btree
 * @array: arr to be sort as btree
 * @ed: Last node in btree
 * @strt: First node of btree
 * @size: Size of the arr to sort
 * Return: 0
 */
void heapify(int *array, int ed, int strt, size_t size)
{
	int mx = strt;
	int l = 2 * strt + 1;
	int r = 2 * strt + 2;

	if (!array || size < 2)
		return;

	if (l < ed && array[l] > array[mx])
		mx = l;

	if (r < ed && array[r] > array[mx])
		mx = r;

	if (strt != mx)
	{
		swp(&array[strt], &array[mx]);
		print_array(array, size);
		heapify(array, ed, mx, size);
	}
}

/**
 * swp - Function that swaps two values
 *
 * @num1: Fisrt value
 * @num2: Second value
 * Return: 0
 */
void swp(int *num1, int *num2)
{
	int temp;

	temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}