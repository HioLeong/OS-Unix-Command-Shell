#!bin/bash
echo Compiling
gcc -c input.c
gcc -c shell.c
gcc -c init.c
gcc shell.o input.o init.o
echo Complete!
