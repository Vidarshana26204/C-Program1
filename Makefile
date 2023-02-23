CC=gcc
CFLAGS=-I.

run: q1main.c
	$(CC) -o run q1main.c

clean:
	-rm run