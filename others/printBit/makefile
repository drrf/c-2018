# Last Modified: May 11, 2018
# GLOBAL DEFINITIONS
CC=gcc
CFLAGS = -ansi -Wall -pedantic

myprog : main.o
	$(CC) -g $(CFLAGS) main.c -o myprog

main.o : main.c
	$(CC) -c $(CFLAGS) main.c -o main.o
