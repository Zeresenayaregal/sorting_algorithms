#include "sort.h"

/**
 * quick_sort - Func that sorts an array based on __
 * quick sort algo
 * @array: Arr to be sort
 * @size: Size of arr
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot;

	if (!array || size < 2)
		return;

	ob_sort(array, size, 1);

	pivot = part(array, size);

	quick_sort(array, pivot);

	quick_sort(array + pivot, size - pivot);
}


/**
 * part - Function that sets the pivot
 *
 * @array: Array to part
 * @size: Size of arr
 * Return: (a + 1)
 */
size_t part(int array[], size_t size)
{
	int pivot;
	size_t a = -1;
	size_t b;

	if (!array || size < 2)
		return (0);

	pivot = array[size - 1];

	for (b = 0; b < size - 1; b++)
	{
		if (array[b] <= pivot)
		{
			a++;
			if (a != b)
			{
				swp(&array[a], &array[b]);
				ob_sort(array, size, 0);
			}
		}
	}
	if (a + 1 != size - 1)
	{
		swp(&array[a + 1], &array[size - 1]);
		ob_sort(array, size, 0);
	}
	return (a + 1);
}

/**
 * ob_sort - Function that prints as it should
 * @array: Array to be printed
 * @size: Size of array
 * @strt: Should initialize array
 * Return: 0
 */
void ob_sort(int array[], size_t size, int strt)
{
	static int *a = (void *)0;
	static size_t b;

	if (!a && strt)
	{
		a = array;
		b = size;
	}
	if (!init)
		print_array(a, b);
}
