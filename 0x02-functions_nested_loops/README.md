# 0x02. C - Functions, Nested Loops

## Description

This project is part of the ALX Low-Level Programming curriculum.  
It focuses on **C functions and nested loops**. You will learn:

- Writing and using functions in C
- Printing characters with `_putchar`
- Looping through alphabets
- Modular programming in multiple files
- Following Betty style guidelines

## Files

| File | Description |
|------|-------------|
| `0-putchar.c` | Prints `_putchar` followed by a new line |
| `1-alphabet.c` | Prints the alphabet in lowercase using a function `print_alphabet` |
| `main.h` | Header file containing function prototypes |

## Compilation

To compile the programs, run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 0-putchar.c -o 0-putchar
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 1-main.c 1-alphabet.c -o 1-alphabet
