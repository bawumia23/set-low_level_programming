#include "main.h"

/**
 * print_number - prints an integer using _putchar
 * @n: number to print
 */
void print_number(int n)
{
	if (n / 10)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}

/**
 * main - prints number of arguments passed into program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argv;

	print_number(argc - 1);
	_putchar('\n');

	return (0);
}
