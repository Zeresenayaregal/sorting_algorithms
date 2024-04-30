#include "sort.h"


/**
 * gp_sort - sort array with gps
 * @array: arr to be sort
 * @size: size of arr
 * @gp: gp size
 */
void gp_sort(int *array, size_t size, unsigned int gp)
{
	size_t a, b;

	for (a = gp; a < size; a++)
	{
		for (b = a; b >= gp && array[b] < array[b - gp]; b -= gp)
		{
			swp(array + b, array + b - gp);
		}
	}
}

/**
 * shell_sort - shell sort
 * @array: arr to be sort
 * @size: size of arr
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gp = 1;

	while (gp < size / 3)
		gp = gp * 3 + 1;

	while (gp >= 1)
	{
		gp_sort(array, size, gp);
		gp = (gp - 1) / 3;
		print_array(array, size);
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