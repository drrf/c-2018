/*
 *          File: printinput.c
 *        Author: Ron F. <>
 * Last Modified: April 25, 2018
 *         Topic: Comparing bytes of to pointer
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h> /* for strlen */
#include "data.h"

void printinput(long len,int b1,int b2, char s[]){

s[strcspn(s,"\n")] = 0;
	
	/* PRINT TO OUTPUT */
	printf("\n----------------------------------------");
	printf("\nAll data were received successfully!!");
	printf("\n----------------------------------------");
	printf("\n\t-LEN = %lu\n\t-*B1 -> STR[%d]=%c\n\t-*B2 -> STR[%d]=%c\n\t-STR [%ld] = {\"%s\"}\n",len,b1,s[b1],b2,s[b2],strlen(s)+1,s);
	printf("----------------------------------------\n");
}
