#include "main.h"

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

	_putchar((argc - 1) + '0');
	_putchar('\n');

	return (0);
}
