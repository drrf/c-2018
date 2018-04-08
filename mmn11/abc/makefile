# Last Modified: April 8, 2018

myprog : main.o getinput.o abc.o valid.o
	gcc -g -ansi -Wall -pedantic main.o getinput.o abc.o valid.o -o myprog

main.o : main.c data.h
	gcc -c -Wall -ansi -pedantic main.c -o main.o

getinput.o : getinput.c data.h
	gcc -c -Wall -ansi -pedantic getinput.c -o getinput.o

abc.o : abc.c data.h
	gcc -c -Wall -ansi -pedantic abc.c -o abc.o

valid.o : valid.c data.h
	gcc -c -Wall -ansi -pedantic valid.c -o valid.o
