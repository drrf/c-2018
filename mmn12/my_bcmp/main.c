/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: April 29, 2018
 *         Topic: Comparing bytes from two pointers
 * ----------------------------------------------------------------
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "data.h" /* for my_bcmp */

/* THIS FUNC RETURN int TO TRANSFER ANSWER FROM my_bcmp */
int getinput();

int main ()
{
	int x;
	system("clear"); /* clear output screen*/

	printf("\n****************************************");
	printf("\n\tThis program comparing bytes from two pointers  \n");
	printf("****************************************\n");

	/* START getinput FILE */
	x = getinput();

	printf("\tReturn from my_bcmp = %d\n",x);
	
	return 0;
}

