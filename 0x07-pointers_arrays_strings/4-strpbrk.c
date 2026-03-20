#include "main.h"

/**
 * _strpbrk - searches string for any of a set of bytes
 * @s: string
 * @accept: bytes to match
 *
 * Return: pointer or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				return (&s[i]);
		}
	}

	return (0);
}
