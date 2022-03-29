# CPSC 380 Assignment 4 - Multi-Threading-Monte-Carlo-Sim

### NOTE: Collaboration project between Jessica Roux and Tarek El-Hajjaoui.

## Description of Program:
- A multi-threaded C program that performs the monte carlo simulation utilizing multiple threads to efficiently perform the calcutions.
- The user provides the number of points to use in the simulation.

## Instructions to run the program:
1. Compile with gcc:
```
gcc mcarlo.c -o mcarlo -Wall
```
2. Run the prgoram:
```
./mcarlo <num of points>
```

## Source Files:
- mcarlo.c
- README.md


## Sources referred to:
- pthread_create: https://man7.org/linux/man-pages/man3/pthread_create.3.html
- pthread_join: https://man7.org/linux/man-pages/man3/pthread_join.3.html
- pthread_attr: https://man7.org/linux/man-pages/man3/pthread_attr_init.3.html
- atoi: https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm
