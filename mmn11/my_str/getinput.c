/*
 *          File: getinput.c
 *        Author: Ron F. <>
 * Last Modified: April 8, 2018
 *         Topic: Found suffix
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include "data.h"

int suffix(char[],char);

void getinput(){
	char ch;
	char str[SIZE];
	
	printf("\t Enter a string (max %d char): ", SIZE);
	fgets(str, SIZE, stdin); 

	printf("\n\t Now, enter char suffix from: ");
	ch = getchar();

	/* START my_str FILE */
	suffix(str,ch);
}
