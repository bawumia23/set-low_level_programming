#include "main.h"

/**
 * _putchar - writes a character to stdout (provided by the system)
 * @c: The character to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c);

/**
 * print_number - prints an integer using _putchar
 * @n: the integer to print
 */
void print_number(int n)
{
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}
	if (num / 10)
		print_number(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * main - prints the number of arguments passed to it
 * @argc: argument count
 * @argv: argument vector (unused)
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	print_number(argc - 1);
	_putchar('\n');
	return (0);
}
