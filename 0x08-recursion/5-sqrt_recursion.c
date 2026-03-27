#include "main.h"

int sqrt_helper(int n, int i);

/**
 * _sqrt_recursion - returns natural square root
 * @n: number
 *
 * Return: sqrt or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 0));
}

/**
 * sqrt_helper - finds sqrt using recursion
 * @n: number
 * @i: guess
 *
 * Return: sqrt or -1
 */
int sqrt_helper(int n, int i)
{
	if (i * i > n)
		return (-1);

	if (i * i == n)
		return (i);

	return (sqrt_helper(n, i + 1));
}
