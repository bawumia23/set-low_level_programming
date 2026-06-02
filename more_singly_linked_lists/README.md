# More Singly Linked Lists

## Description
This project is part of the ALX Low Level Programming curriculum.
It covers more advanced operations on singly linked lists in C,
including safe traversal of lists that contain loops.

## Requirements
- Ubuntu 20.04 LTS
- gcc with options: -Wall -Werror -Wextra -pedantic -std=gnu89
- Betty style compliant

## Data Structure
```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Files

| File | Description |
|------|-------------|
| `8-sum_listint.c` | Returns the sum of all data in a listint_t linked list |
| `9-insert_nodeint.c` | Inserts a new node at a given position |
| `10-delete_nodeint.c` | Deletes the node at a given index |
| `100-reverse_listint.c` | Reverses a listint_t linked list |
| `101-print_listint_safe.c` | Prints a linked list safely (handles loops) |
| `102-free_listint_safe.c` | Frees a linked list safely (handles loops) |
| `103-find_loop.c` | Finds the node where a loop starts |
| `lists.h` | Header file with all prototypes |

## Author
Tajudeen
