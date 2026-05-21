#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @n: The integer to print
 */
void print_number(int n)
{
	if (n / 10)
		print_number(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * main - Prints the number of arguments passed into it
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	print_number(argc - 1);
	_putchar('\n');

	return (0);
}
