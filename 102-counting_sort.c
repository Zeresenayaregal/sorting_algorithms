#include "sort.h"
#include <limits.h>
#include <stdlib.h>

/**
 * g_max - Find mx in arr of ints
 *
 * @array: array to find mx val
 * @size: size of the array
 * Return: 0
 */
int g_max(int *array, size_t size)
{
	int mx = INT_MIN;

	while (size--)
		if (array[size] > mx)
			mx = array[size];

	return (mx);
}

/**
 * counting_sort - sort an array
 * @array: array to sort
 * @size: size of array to sort
 */
void counting_sort(int *array, size_t size)
{
	int *temp, *cpy, b, mx;
	size_t a;

	if (!array || size < 2)
		return;

	mx = g_max(array, size);
	temp = calloc(mx + 1, sizeof(*temp));
	if (!temp)
		return;

	cpy = malloc(sizeof(*cpy) * size);
	if (!cpy)
	{
		free(temp);
		return;
	}
	
	a = 0;

	while (a < size)
	{
		temp[array[a]]++;
		a++;
	}

	b = 1

	while (b < mx + 1)
	{
		temp[b] += temp[b - 1];
		b++;
	}

	print_array(temp, mx + 1);


	a = 0;

	while (a < size)
	{
		temp[array[a]]--;
		cpy[temp[array[a]]] = array[a];
		a++;
	}

	a = 0;
	while (a < size)
	{
		array[a] = cpy[a];
		a++;
	}

	free(temp);
	free(cpy);
}
