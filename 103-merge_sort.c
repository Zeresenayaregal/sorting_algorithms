#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_helper - staring ... merge sort
 * @array: arr to be sort
 * @temp: tempo arr for holding sorted elts
 * @size: size of the arr
 */
void merge_helper(int *array, int *temp, size_t size)
{
	size_t h = size / 2, a = 0, b = 0, c;

	if (size < 2)
		return;

	merge_helper(array, temp, h);
	merge_helper(array + h, temp + h, size - h);

	printf("%s", "Merging...\n");
	printf("%s", "[left]: ");
	print_array(array, h);
	printf("%s", "[right]: ");
	print_array(array + h, size - h);
	for (c = 0; c < size; c++)
		if (b >= size - h || (a < h && array[a] < (array + h)[b]))
		{
			temp[c] = array[a];
			a++;
		}
		else
		{
			temp[c] = (array + h)[b];
			b++;
		}
	for (c = 0; c < size; c++)
		array[c] = temp[c];
	printf("%s", "[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - initiate merge sort
 * @array: arr to be sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	merge_helper(array, temp, size);
	free(temp);
}
