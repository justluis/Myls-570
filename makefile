CC=gcc
CFLAGS=-I.

make: myls.o
        $(CC) -o myls -std=c99 myls.o