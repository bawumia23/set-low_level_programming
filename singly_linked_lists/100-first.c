#include <stdio.h>

/**
 * tortoise_first - prints a message before main
 */
void tortoise_first(void) __attribute__((constructor));

void tortoise_first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
