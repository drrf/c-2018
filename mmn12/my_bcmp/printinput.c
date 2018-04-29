/*
 *          File: printinput.c
 *        Author: Ron F. <>
 * Last Modified: April 26, 2018
 *         Topic: Comparing bytes from two pointers
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h> /* for strlen */

void printinput(long len,int b1,int b2, char s[]){

/* THIS LINE ONLY FOR COSMETIC FIX */
s[strcspn(s,"\n")] = 0;

if (strlen(s) != 0){

/* PRINT TO OUTPUT */
	printf("\n----------------------------------------");
	printf("\nAll data were received successfully!!");
	printf("\n----------------------------------------");
	printf("\n\t-LEN = %lu\n\t-*B1 -> STR[%d]=%c\n\t-*B2 -> STR[%d]=%c\n\t-STR [%ld] = {\"%s\"}\n",len,b1,s[b1],b2,s[b2],strlen(s)+1,s);
	printf("----------------------------------------\n");
} else {
	printf("\n----------------------------------------");
	printf("\nWARNING: Not All data were received!!");
	printf("\n----------------------------------------");
	printf("\n\t-LEN = %lu\n\t-*B1 -> STR[%d]=%c\n\t-*B2 -> STR[%d]=%c\n\t-STR [] = {\'\\0\'}\n",len,b1,s[b1],b2,s[b2]);
	printf("----------------------------------------\n");
}
}
