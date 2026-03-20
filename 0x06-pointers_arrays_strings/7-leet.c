#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string
 *
 * Return: pointer to string
 */
char *leet(char *str)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char nums[] = "4433007711";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; letters[j]; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = nums[j];
				break;
			}
		}
	}

	return (str);
}
