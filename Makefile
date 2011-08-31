CC = gcc
CFLAGS = -g
 
all:
	gcc -c binstr.c -o binstr.o
	gcc -c test.c -o test.o
	gcc binstr.o test.o -o test
 
clean:
	rm -f test binstr.o test.o

