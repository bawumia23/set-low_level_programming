# 0x0A. argc, argv

## 📘 Description

This project focuses on understanding how command-line arguments work in C using `argc` and `argv`.

- `argc` (Argument Count) represents the number of arguments passed to the program.
- `argv` (Argument Vector) is an array of strings containing the arguments.

This project demonstrates how to:
- Access and print program arguments
- Count arguments
- Perform operations using command-line inputs

---

## 📂 Files

### 0-whatsmyname.c
Prints the name of the program.

### 1-args.c
Prints the number of arguments passed to the program.

### 2-args.c
Prints all arguments received, including the program name.

### 3-mul.c
Multiplies two numbers passed as arguments.  
Prints `Error` if exactly two arguments are not provided.

### 4-add.c
Adds positive numbers passed as arguments.  
- Prints `0` if no arguments are given  
- Prints `Error` if any argument is not a number  

---

## 🛠️ Compilation

All files are compiled using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 file.c -o output
./mynameis
./nargs hello world
./args Hello World
./mul 2 3
./add 1 2 3 4

Author;- 
Tajudeen Bawumia
