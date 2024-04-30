#include <stdio.h>
#include "sort.h"

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
