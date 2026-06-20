# 0x1A. Hash Tables

## Description

This project implements a Hash Table data structure in C, using **chaining**
to handle collisions. A hash table is a data structure that maps keys to
values for highly efficient lookup, using a hash function to compute an
index into an array of buckets, from which the desired value can be found.

Each bucket in the underlying array is the head of a singly linked list
(a chain). When two different keys hash to the same index, the new
key/value pair is simply added to the front of that bucket's list.

This project is part of the ALX Low-Level Programming curriculum.

## Learning Objectives

At the end of this project, you should be able to explain:

- What a hash table is, and what it is used for
- What a collision is, and how to handle it
- What is a good hash function
- What is the major disadvantage of hash tables
- What is the time complexity of insertion, deletion and access in:
  - A hash table where collisions are handled by chaining
  - A sorted array of pairs (key, values)

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- Compiled on Ubuntu 20.04 LTS using `gcc`, with options
  `-Wall -Wextra -Werror -pedantic -std=gnu89`
- All files end with a new line
- A `README.md` file at the root of the project folder is mandatory
- Code follows the [Betty style](https://github.com/holbertonschool/Betty-doc)
- No more than 5 functions per file
- All header files are include guarded
- Global variables are not allowed
- More than one loop per function is not allowed

## Data Structures

```c
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;
```

## Files

| File | Description |
| --- | --- |
| `hash_tables.h` | Header file with struct definitions and function prototypes |
| `0-hash_table_create.c` | Creates a hash table |
| `1-djb2.c` | Implements the djb2 hash algorithm |
| `2-key_index.c` | Gives the index of a key in the array of the hash table |
| `3-hash_table_set.c` | Adds an element to a hash table |
| `4-hash_table_get.c` | Retrieves a value associated with a key |
| `5-hash_table_print.c` | Prints a hash table |
| `6-hash_table_delete.c` | Deletes a hash table |

## Function Prototypes

```c
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);
```

## Usage

Each task can be compiled together with its corresponding `*-main.c` test
file, for example:

```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 \
    6-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c \
    3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c \
    6-hash_table_delete.c -o hash_table_test

./hash_table_test
```

To check for memory leaks:

```bash
valgrind --leak-check=full ./hash_table_test
```

## Example

```
$ cat 5-main.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	hash_table_print(ht);
	hash_table_set(ht, "c", "fun");
	hash_table_set(ht, "python", "awesome");
	hash_table_set(ht, "Bob", "and Kris love asm");
	hash_table_set(ht, "N", "queens");
	hash_table_set(ht, "Asterix", "Obelix");
	hash_table_set(ht, "Betty", "Cool");
	hash_table_set(ht, "98", "Battery Street");
	hash_table_print(ht);
	return (EXIT_SUCCESS);
}
$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c 5-hash_table_print.c -o f
$ ./f
{}
{'Betty': 'Cool', 'python': 'awesome', 'Bob': 'and Kris love asm', '98': 'Battery Street', 'N': 'queens', 'c': 'fun', 'Asterix': 'Obelix'}
```

## Author

Adamu Tajudeen Bawumia
