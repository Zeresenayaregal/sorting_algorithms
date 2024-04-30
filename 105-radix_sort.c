#include "sort.h"

/**
 * radix_sort -
 *
 * Return: 
 */

int mx(int *a, int s);
void rcs(int *a, size_t s, int d, int *b);
void rs(int *a, size_t s);

int mx(int *a, int s)
{
	int m, i;

	for (m = a[0], i = 1; i < s; i++)
	{
		if (a[i] > m)
			m = a[i];
	}

	return m;
}

void rcs(int *a, size_t s, int d, int *b)
{
	int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < s; i++)
		c[(a[i] / d) % 10] += 1;

	i = 0;
	while (i < 10)
	{
		c[i] += c[i - 1];
		i++;
	}

	i = s - 1;
	while (i >= 0)
	{
		b[c[(a[i] / d) % 10] - 1] = a[i];
		c[(a[i] / d) % 10] -= 1;
		i--;
	}

	i = 0;
	while (i < s)
	{
		a[i] = b[i];
		i++;
	}
}

void rs(int *a, size_t s)
{
	int m, d, *b;

	if (a == NULL || s < 2)
		return;

	b = malloc(sizeof(int) * s);
	if (b == NULL)
		return;

	m = mx(a, s);
	d = 1;
	while (m / d > 0)
	{
		rcs(a, s, d, b);
		print_array(a, s);
		d *= 10;
	}

	free(b);
}