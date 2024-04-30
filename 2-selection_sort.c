#include "sort.h"

/**
 * selection_sort - Calls func
 * @array: Arr to be sort
 * @size: Size of arr given
 * Return: 0
 */
void selection_sort(int *array, size_t size)
{
	unsigned int a, b, mini;

	if (!array)
		return;

	for (a = 0; a < size - 1; a++)
	{
		mini = a;
		for (b = a + 1; b < size; b++)
			if (array[b] < array[mini])
				mini = b;

		if (a != mini)
		{
			swp(&array[mini], &array[a]);
			print_array(array, size);
		}
	}
}
