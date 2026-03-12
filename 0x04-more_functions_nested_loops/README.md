# 0x04. More Functions, Nested Loops

## Description

This project focuses on practicing more C functions and the use of nested loops.
The tasks involve creating functions that perform character checks, arithmetic operations, and printing different patterns using loops.

The goal is to strengthen understanding of:

* Functions in C
* Nested loops
* ASCII character manipulation
* Writing modular and reusable code
* Following strict coding style guidelines

All output operations (except the FizzBuzz program) are implemented using the `_putchar` function.

---

## Learning Objectives

At the end of this project, you should be able to explain:

* How to use nested loops in C
* How to write functions that perform specific tasks
* The difference between characters and integers in ASCII
* How to build simple programs without using the standard output functions like `printf`
* How to follow the Betty coding style
* How to organize prototypes in header files

---

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* All files compiled on **Ubuntu 20.04 LTS**
* Compilation flags:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

* All files must end with a new line
* Code must follow **Betty style**
* No global variables
* No more than **5 functions per file**
* All prototypes must be declared in **main.h**
* `_putchar` is the only function allowed for output (except in `9-fizz_buzz.c`)
* `_putchar.c` will be provided by the checker and **must not be pushed**

---

## Files

| File                     | Description                                             |
| ------------------------ | ------------------------------------------------------- |
| `0-isupper.c`            | Function that checks for uppercase characters           |
| `1-isdigit.c`            | Function that checks for digits (0–9)                   |
| `2-mul.c`                | Function that multiplies two integers                   |
| `3-print_numbers.c`      | Prints numbers from 0 to 9                              |
| `4-print_most_numbers.c` | Prints numbers except 2 and 4                           |
| `5-more_numbers.c`       | Prints numbers from 0 to 14 ten times                   |
| `6-print_line.c`         | Draws a straight line using `_`                         |
| `7-print_diagonal.c`     | Draws a diagonal line using `\`                         |
| `8-print_square.c`       | Prints a square using `#`                               |
| `9-fizz_buzz.c`          | Program that prints the FizzBuzz sequence from 1 to 100 |
| `10-print_triangle.c`    | Prints a triangle using `#`                             |
| `main.h`                 | Header file containing all function prototypes          |

---

## Example Compilation

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-print_numbers.c _putchar.c -o 3-print_numbers
./3-print_numbers
```

Output:

```
0123456789
```

---

## Author

**Tajudeen Bawumia**

