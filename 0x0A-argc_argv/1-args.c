#include "main.h"

/**
 * main - prints the number of arguments passed into it
 * @argc: number of arguments
 * @argv: array of strings (unused)
 *
 * Return: 0
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	int count = argc - 1;
	int temp, divisor = 1;

	if (count == 0)
	{
		_putchar('0');
	}
	else
	{
		temp = count;
		/* Find the highest power of 10 to start printing from the left */
		while (temp / 10 > 0)
		{
			divisor *= 10;
			temp /= 10;
		}

		while (divisor > 0)
		{
			_putchar(((count / divisor) % 10) + '0');
			divisor /= 10;
		}
	}
	_putchar('\n');

	return (0);
}
