#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARSET "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"

/**
 * get_indices - compute all 6 key indices from username
 * @username: the username string
 * @n: length of username
 * @idx: output array of 6 indices
 */
static void get_indices(const char *username, int n, int *idx)
{
	int sum, product, max, sumsq, last, i, count;

	sum = 0;
	product = 1;
	max = (int)username[0];
	sumsq = 0;

	for (i = 0; i < n; i++)
	{
		sum += (int)username[i];
		product *= (int)username[i];
		if ((int)username[i] > max)
			max = (int)username[i];
		sumsq += (int)username[i] * (int)username[i];
	}

	idx[0] = (n ^ 0x3b) & 0x3f;
	idx[1] = (sum ^ 0x4f) & 0x3f;
	idx[2] = (product ^ 0x55) & 0x3f;

	srand((unsigned int)(max ^ 0xe));
	idx[3] = rand() & 0x3f;

	idx[4] = (sumsq ^ 0xef) & 0x3f;

	count = (int)username[0];
	last = 0;
	for (i = 0; i < count; i++)
		last = rand();
	idx[5] = (last ^ 0xe5) & 0x3f;
}

/**
 * main - print the valid crackme5 key for a given username
 * @argc: argument count
 * @argv: argument vector, argv[1] = username
 * Return: (0) on success, (1) on error
 */
int main(int argc, char *argv[])
{
	const char *charset = CHARSET;
	const char *username;
	int n, idx[6], i;
	char key[7];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}

	username = argv[1];
	n = (int)strlen(username);

	get_indices(username, n, idx);

	for (i = 0; i < 6; i++)
		key[i] = charset[idx[i]];
	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}
