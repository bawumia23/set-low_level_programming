# C - Variables, if, else, while

This project covers:
- Arithmetic operators and variables
- Conditional statements (if, else if, else)
- Loops (while)
- Random number generation in C

## Files

| Filename | Description |
|----------|-------------|
| 1-last_digit.c | Prints the last digit of a random number |

## Requirements
- Ubuntu 20.04 LTS
- gcc flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- Betty style compliant

## Tasks
0. **Positive anything is better than negative nothing** - Program that prints whether a random number is positive, negative, or zero
   - File: 0-positive_or_negative.c
   - Uses if/else if/else conditions
   - Random numbers generated each run

2. **I sometimes suffer from insomnia** - Program that prints the alphabet in lowercase
   - File: 2-print_alphabet.c
   - Uses only putchar (twice)
   - Uses a loop to iterate through letters

3. **alphABET** - Program that prints lowercase then uppercase alphabet
   - File: 3-print_alphabets.c
   - Uses only putchar (three times)
   - Two loops: one for lowercase, one for uppercase

4. **When I was having that alphabet soup** - Program that prints alphabet except 'e' and 'q'
   - File: 4-print_alphabt.c
   - Uses only putchar (twice)
   - Uses if condition to skip specific letters

5. **Print numbers** - Program that prints all single digit numbers of base 10 (0-9)
   - File: 5-print_numbers.c
   - Uses putchar to print digits
   - Loop from 0 to 9

6. **Numberz** - Program that prints numbers 0-9 without using char variables
   - File: 6-print_numberz.c
   - Uses only int variables
   - Uses putchar twice only
   - Converts int to ASCII using '0' + num

7. **Smile in the mirror** - Program that prints lowercase alphabet in reverse
   - File: 7-print_tebahpla.c
   - Uses only putchar (twice)
   - Loop from 'z' down to 'a'

8. **Hexadecimal** - Program that prints all numbers of base 16 in lowercase
   - File: 8-print_base16.c
   - Prints: 0123456789abcdef
   - Uses putchar three times
   - Two loops: one for digits 0-9, one for letters a-f

9. **Patience, persistence and perspiration** - Program that prints combinations of single-digit numbers
   - File: 9-print_comb.c
   - Prints: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
   - Uses putchar (max 4 times)
   - No char variables (only int)
   - Adds comma and space after each number except the last
