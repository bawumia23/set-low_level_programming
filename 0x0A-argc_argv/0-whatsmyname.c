#include "main.h"

/**
 * _putchar - writes a character to stdout (provided by the system)
 * @c: The character to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c);

/**
 * main - prints its name, followed by a new line
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int i = 0;

	while (argv[0][i] != '\0')
	{
		_putchar(argv[0][i]);
		i++;
	}
	_putchar('\n');
	return (0);
}
