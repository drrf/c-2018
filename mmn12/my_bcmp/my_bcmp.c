/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: April 17, 2018
 *         Topic: Comparing bytes of to pointer
 * ----------------------------------------------------------------
 */
#include <stdio.h>
#include <stddef.h>

int my_bcmp (const void *b1, const void *b2, size_t len){
	int i = 0;
	int ch1, ch2;

	for (i=0; i<=len; i++){
		ch1 = *((char *)b1+i);
		ch2 = *((char *)b2+i);
		if(ch1 == ch2){
			printf("\n\t Yes");
			printf("\n\t i=%d, ch1 = %c",i,ch1);
			printf("\n\t i=%d, ch2 = %c",i,ch2);
		} else {
			printf("\n\t No");
			printf("\n\t ch1 = %c", ch1);
			printf("\n\t ch2 = %c", ch2);			
			break;
		}
	}
	printf("\n\t Yes/no\n");

	return i;
}
