#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * charset - 64-character lookup table used by crackme5
 * Extracted from the movabs instructions in crackme5's main function
 */
static const char charset[] =
	"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

/**
 * f1 - index derived from username length
 * @n: length of username
 * Return: (n ^ 0x3b) & 0x3f
 */
static int f1(int n)
{
	return (n ^ 0x3b) & 0x3f;
}

/**
 * f2 - index derived from sum of username characters
 * @username: the username string
 * @n: length of username
 * Return: (sum_of_chars ^ 0x4f) & 0x3f
 */
static int f2(const char *username, int n)
{
	int sum = 0;
	int i;

	for (i = 0; i < n; i++)
		sum += (int)username[i];
	return (sum ^ 0x4f) & 0x3f;
}

/**
 * f3 - index derived from product of username characters
 * @username: the username string
 * @n: length of username
 * Return: (product_of_chars ^ 0x55) & 0x3f
 */
static int f3(const char *username, int n)
{
	int product = 1;
	int i;

	for (i = 0; i < n; i++)
		product *= (int)username[i];
	return (product ^ 0x55) & 0x3f;
}

/**
 * f4 - index derived from max char, seeds srand, calls rand once
 * @username: the username string
 * @n: length of username
 * Return: rand() & 0x3f  (after seeding with max_char ^ 0xe)
 * Side-effect: seeds the global rand state used by f6
 */
static int f4(const char *username, int n)
{
	int max = (int)username[0];
	int i;

	for (i = 0; i < n; i++)
		if ((int)username[i] > max)
			max = (int)username[i];
	srand((unsigned int)(max ^ 0xe));
	return rand() & 0x3f;
}

/**
 * f5 - index derived from sum of squares of username characters
 * @username: the username string
 * @n: length of username
 * Return: (sum_of_squares ^ 0xef) & 0x3f  (low byte xor only)
 */
static int f5(const char *username, int n)
{
	int sum = 0;
	int i;

	for (i = 0; i < n; i++)
		sum += (int)username[i] * (int)username[i];
	return (sum ^ 0xef) & 0x3f;
}

/**
 * f6 - index from calling rand() username[0] times after f4 seeded it
 * @username: the username string
 * Return: (last_rand ^ 0xe5) & 0x3f
 * Must be called after f4 to use the same rand sequence
 */
static int f6(const char *username)
{
	int count = (int)username[0];
	int last = 0;
	int i;

	for (i = 0; i < count; i++)
		last = rand();
	return (last ^ 0xe5) & 0x3f;
}

/**
 * main - print the valid crackme5 key for a given username
 * @argc: argument count
 * @argv: argument vector, argv[1] = username
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	const char *username;
	int n;
	char key[7];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}

	username = argv[1];
	n = (int)strlen(username);

	key[0] = charset[f1(n)];
	key[1] = charset[f2(username, n)];
	key[2] = charset[f3(username, n)];
	key[3] = charset[f4(username, n)]; /* seeds srand - must come before f6 */
	key[4] = charset[f5(username, n)];
	key[5] = charset[f6(username)];    /* uses rand state from f4 */
	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}
