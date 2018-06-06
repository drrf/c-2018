# Last Modified: June 6, 2018
# GLOBAL DEFINITIONS
# Run the prog example: "./myprog data.in chair"

CC=gcc
CFLAGS = -g -ansi -Wall -pedantic

myprog : permut.o
	$(CC) -g -ansi -Wall -pedantic permut.o -o myprog

permut.o : permut.c
	gcc -c -Wall -ansi -pedantic permut.c -o permut.o

run:
	./myprog < in1.txt > out1.txt
	./myprog < int2.txt > out2.txt

gdb:
	gdb ./myprog

clean:
	rm -f *.o
