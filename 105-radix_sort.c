#include "sort.h"

/**
 * mx - Find the maximum value in an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 * Return: The maximum value in the array.
 */


int mx(int *array, int size)
{
	int m, i;

	for (m = array[0], i = 1; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	}

	return m;
}


/**
 * rcs - Perform counting sort on a given digit.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @d: The digit to perform counting sort on.
 * @b: Temporary array for storing sorted elements.
 */

void rcs(int *array, size_t size, int d, int *b)
{
	int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		c[(array[i] / d) % 10] += 1;

	i = 0;
	while (i < 10)
	{
		c[i] += c[i - 1];
		i++;
	}

	i = size - 1;
	while (i >= 0)
	{
		b[c[(array[i] / d) % 10] - 1] = array[i];
		c[(array[i] / d) % 10] -= 1;
		i--;
	}

	i = 0;
	while (i < size)
	{
		array[i] = b[i];
		i++;
	}
}


/**
 * radix_sort - Sort an array of ints
 * @array: Pointer to the array.
 * @size: Size of the array.
 *
 */
void radix_sort(int *array, size_t size);
{
	int m, d, *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	m = mx(array, size);
	d = 1;
	while (m / d > 0)
	{
		rcs(array, size, d, b);
		print_array(array, size);
		d *= 10;
	}

	free(b);
}