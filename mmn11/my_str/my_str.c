/*
 *          File: my_str.c
 *        Author: Ron F. <>
 * Last Modified: April 5, 2018
 *         Topic: Found sequence
 * ----------------------------------------------------------------
 */
#include <stdio.h>
# include <string.h>
#include "data.h"

int suffix(char str[SIZE], char ch){	
	int i, len, suf = 0;
	char copystr[SIZE];
	
	/* SAVE THE LENGTH OF THE STRING */
	len = strlen(str); 
	
	printf("\n");

	/* COUNT & DISPLAY THE SUFFIX IN THE STRING */
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (ch == str[i]){
			++suf;
			strncpy(copystr, str+i,len);
			printf("\t%d. %s", suf,copystr);
		}
	}

	printf("\n----------------------------------------\n");
	printf("\tThe num of suffix is: %d \n", suf);
	printf("----------------------------------------\n");
	
	return suf;
}

