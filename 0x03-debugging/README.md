# 0x03. Debugging

## Project Description
This project is part of the Low-Level Programming curriculum.  
It focuses on **debugging C programs**, identifying and fixing:

- Logical errors  
- Infinite loops  
- Incorrect conditions for leap years  
- Errors in comparisons  

---

## Files

| File                     | Description |
|---------------------------|------------|
| `0-main.c`                | Tests `positive_or_negative()` function with `0` |
| `1-main.c`                | Demonstrates and fixes an infinite loop |
| `2-largest_number.c`      | Returns the largest of three integers |
| `2-main.c`                | Tests `largest_number()` function |
| `3-convert_day.c`         | Converts month/day to day-of-year (ignores leap years) |
| `3-print_remaining_days.c`| Prints remaining days in year, handles leap years |
| `3-main_a.c`              | Test for normal year date |
| `3-main_b.c`              | Test for leap year date |
| `main.h`                  | Header file with function prototypes |

---

## How to Compile

Example:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c positive_or_negative.c -o 0-main
./0-main
