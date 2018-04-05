/*
 *          File: getinput.c
 *        Author: Ron F. <>
 * Last Modified: April 5, 2018
 *         Topic: Found sequence
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include "data.h"

void abc(char[]);

void getinput(){
	char str[SIZE];
	
	printf("\n\t Enter a string (max %d char): ", SIZE);
	fgets(str, SIZE, stdin); 

	/* START abc FILE */
	abc(str);
}
