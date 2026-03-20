#include "main.h"

/**
 * cap_string - capitalizes all words
 * @str: string
 *
 * Return: pointer to string
 */
char *cap_string(char *str)
{
	int i = 0, j;
	char sep[] = " \t\n,;.!?\"(){}";

	while (str[i])
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;

		for (j = 0; sep[j]; j++)
		{
			if (str[i] == sep[j])
			{
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
					str[i + 1] -= 32;
			}
		}
		i++;
	}

	return (str);
}
