/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: April 3, 2018
 *         Topic: Show program process PID and kill
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* PID */

int main (){
	int id;
	char buf[BUFSIZ];  

	system("ps axu");
	printf("\n****************************************\n");
	printf("My process ID: %d\n", getpid());
	printf("My parent's ID: %d\n", getppid);
	printf("****************************************\n");

	snprintf(buf, sizeof(buf), "kill %d",getpid());
	system(buf); 

	/* WAITING */
	scanf("%d", &id); 
return 0;
}
