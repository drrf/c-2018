# comment demo

myprog : main.o getinput.o my_str.o
	gcc -g -ansi -Wall -pedantic main.o getinput.o my_str.o -o myprog

main.o : main.c data.h
	gcc -c -Wall -ansi -pedantic main.c -o main.o

getinput.o : getinput.c data.h
	gcc -c -Wall -ansi -pedantic getinput.c -o getinput.o

my_str.o : my_str.c data.h
	gcc -c -Wall -ansi -pedantic my_str.c -o my_str.o
