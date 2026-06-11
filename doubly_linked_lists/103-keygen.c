#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a valid key for a given username for crackme5.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *username;
	int len, i;
	unsigned int hash = 1337; /* Initial seed value used by crackme5 */

	if (argc != 2)
	{
		return (1);
	}

	username = argv[1];
	len = strlen(username);

	/* Replicating the internal hashing loop of crackme5 */
	for (i = 0; i < len; i++)
	{
		hash += username[i];
	}

	/* Print the generated key based on the final hash score */
	/* Note: Adjust the printing format if your specific binary version expects a string mapping */
	printf("%u\n", hash);

	return (0);
}
