#include "sort.h"

/**
 * bubble_sort - Calls func
 * @array: arr to be sorted
 * @size: Size of arr
 * Return: 0
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int a, b;

	if (!array)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				swp(&array[b], &array[b + 1]);
				print_array(array, size);
			}
		}
	}
}
