# 0x08. Recursion

## Description

This project focuses on understanding and implementing **recursion in C**. Recursion is a programming technique where a function calls itself to solve a problem.

The goal is to replace iterative solutions (loops) with recursive approaches while following strict coding constraints.

---

## Learning Objectives

By completing this project, you should be able to:

* Understand what recursion is
* Explain how recursive functions work
* Identify base cases and recursive cases
* Solve problems using recursion instead of loops

---

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* Compilation: Ubuntu 20.04 LTS using:

  ```
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89
  ```
* All files must end with a new line
* Code must follow **Betty style**
* No global variables
* Maximum of 5 functions per file
* No loops allowed (`for`, `while`, etc.)
* No static variables
* No use of standard library functions like `printf`, `puts`, etc.
* Only `_putchar` is allowed for output
* `_putchar.c` should not be pushed to the repository
* All function prototypes must be in `main.h`

---

## Files and Functions

| File                      | Description                                 |
| ------------------------- | ------------------------------------------- |
| `0-puts_recursion.c`      | Prints a string followed by a new line      |
| `1-print_rev_recursion.c` | Prints a string in reverse                  |
| `2-strlen_recursion.c`    | Returns the length of a string              |
| `3-factorial.c`           | Returns the factorial of a number           |
| `4-pow_recursion.c`       | Returns x raised to the power of y          |
| `5-sqrt_recursion.c`      | Returns the natural square root of a number |
| `6-is_prime_number.c`     | Checks if a number is prime                 |

---

## Compilation Example

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c 0-main.c 0-puts_recursion.c -o 0-puts
./0-puts
```

---

## Example Output

```
Puts with recursion
```

---

## Author

* **Tajudeen Bawumia**

---

## Notes

* Every recursive function must have a **base case** to avoid infinite recursion.
* Recursive solutions may use more memory due to function call stack.
* Always test your code with multiple inputs, including edge cases.

---

