#include "sort.h"

/**
  * shell_sort - A function of shell algo.
  * @array: The arr to sort.
  * @size: The len of the arr.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int a = 0, b = 0, gp = 1;
	int mnc = 0;

	if (array == NULL || size < 2)
		return;

	while (gp < size / 3)
		gp = gp * 3 + 1;

	for (; gp > 0; gp = (gp - 1) / 3)
	{
		for (a = gp; a < size; a++)
		{
			mnc = array[a];
			for (b = a; b >= gp && array[b - gp] > mnc; b -= gp)
			{
				array[b] = array[b - gp];
			}
			array[b] = mnc;
		}
		print_array(array, size);
	}
}
