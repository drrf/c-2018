/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: April 25, 2018
 *         Topic: Comparing bytes from two pointers
 * ----------------------------------------------------------------
 */
#include <stdio.h>
#include <stddef.h> /* for size_t */

int my_bcmp (const void *b1, const void *b2, size_t len){
	int i = 0;
	int ch1, ch2;

	/* CHECK 0 LEN */
	if (len == 0){
		printf("\n\t( NOTE: LEN 0 DEFAULT RETURN 0 )\n");
		return 0;
	}

	for (i=0; i<len; i++){
		ch1 = *((char *)b1+i);
		ch2 = *((char *)b2+i);
		if(ch1 != ch2){
			if (ch1 < ch2)
				return -1;
			else
				return 1;			
		}
	} /* END OF FOR */
	return 0;
}
