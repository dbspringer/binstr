CC = gcc
CFLAGS = -g
 
all:
	$(CC) $(CFLAGS) -c binstr.c -o binstr.o
	$(CC) $(CFLAGS) -c test.c -o test.o
	$(CC) binstr.o test.o -o test
 
clean:
	rm -f test binstr.o test.o

