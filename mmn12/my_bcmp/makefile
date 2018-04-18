# Last Modified: April 17, 2018

myprog : main.o getinput.o valid.o my_bcmp.o
	gcc -g -ansi -Wall -pedantic main.o getinput.o valid.o my_bcmp.o -o myprog

main.o : main.c data.h
	gcc -c -Wall -ansi -pedantic main.c -o main.o

getinput.o : getinput.c data.h
	gcc -c -Wall -ansi -pedantic getinput.c -o getinput.o

valid.o : valid.c data.h
	gcc -c -Wall -ansi -pedantic valid.c -o valid.o

my_bcmp.o : my_bcmp.c data.h
	gcc -c -Wall -ansi -pedantic my_bcmp.c -o my_bcmp.o
