/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: April 5, 2018
 *         Topic: Found suffix
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

int suffix(char[],char);
void getinput();

int main ()
{
	system("clear");  /*clear output screen*/

	printf("\n****************************************");
	printf("\n\tThis program found suffix in string\n");
	printf("****************************************\n");
	
	/* START getinput FILE */
	getinput();
	
	return 0;
}

