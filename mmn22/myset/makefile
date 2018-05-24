# Last Modified: May 8, 2018
# GLOBAL DEFINITIONS
CC=gcc
CFLAGS = -g -ansi -Wall -pedantic

myprog : myset.o set.o func.o err.o
	$(CC) -g -ansi -Wall -pedantic myset.o set.o func.o err.o -o myprog

myset.o : myset.c set.h
	gcc -c -Wall -ansi -pedantic myset.c -o myset.o

set.o : set.c set.h
	gcc -c -Wall -ansi -pedantic set.c -o set.o

func.o : func.c set.h
	gcc -c -Wall -ansi -pedantic func.c -o func.o

err.o : err.c set.h
	gcc -c -Wall -ansi -pedantic err.c -o err.o

run:
	./myprog < in1.txt > out1.txt
	./myprog < int2.txt > out2.txt

gdb:
	gdb ./myprog

clean:
	rm -f *.o
