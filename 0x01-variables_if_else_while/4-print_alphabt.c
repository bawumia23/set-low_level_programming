#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* Loop through all letters from a to z */
	for (letter = 'a'; letter <= 'z'; letter++)
	{
		/* Skip 'e' and 'q' */
		if (letter != 'e' && letter != 'q')
		{
			putchar(letter);  /* First putchar - prints letters except e and q */
		}
	}
	putchar('\n');  /* Second putchar - prints newline */

	return (0);
}
