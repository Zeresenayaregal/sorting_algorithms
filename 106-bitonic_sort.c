#include "sort.h"


#define U 1
#define D 2

/**
 * b_m - Sort a bitonic squence.
 * @array: An arr of ints.
 * @size: The size of the array.
 * @strt: The strting idx
 * @sq: The s of the squence.
 * @fw: The dir to sort in.
 */
void b_m(int *array, size_t size, size_t strt, size_t sq,
		char fw)
{
	size_t i, jmp = sq / 2;

	if (sq > 1)
	{
		for (i = strt; i < strt + jmp; i++)
		{
			if ((fw == U && array[i] > array[i + jmp]) ||
			    (fw == D && array[i] < array[i + jmp]))
				swp(array + i, array + i + jmp);
		}
		b_m(array, size, strt, jmp, fw);
		b_m(array, size, strt + jmp, jmp, fw);
	}
}

/**
 * b_sq - Convert an arr of ints into a bit.
 * @array: An array of ints.
 * @size: The size of the arr.
 * @strt: The srt idx.
 * @sq: The size of a block.
 * @fw: The direction to sort.
 */
void b_sq(int *array, size_t size, size_t strt, size_t sq, char fw)
{
	size_t vt = sq / 2;
	char *str = (fw == U) ? "U" : "D";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + strt, sq);

		b_sq(array, size, strt, vt, U);
		b_sq(array, size, strt + vt, vt, D);
		b_m(array, size, strt, sq, fw);

		printf("Result [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + strt, sq);
	}
}

/**
 * bitonic_sort - Sort an array of ints in asc ord
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	b_sq(array, size, 0, size, U);
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
