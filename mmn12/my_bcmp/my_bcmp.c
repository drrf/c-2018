/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: April 29, 2018
 *         Topic: Comparing bytes from two pointers
 * ----------------------------------------------------------------
 */
#include <stdio.h>
#include <stddef.h> /* for size_t */
#include <string.h> /* for strlen */
#include <stdlib.h> /* for exit */
#include "data.h"

int valid_bcmp(size_t,const void *,const void *);

int my_bcmp (const void *b1, const void *b2, size_t len){
	int i = 0;
	int ch1, ch2;

	/* CHECK VALID */
	if (valid_bcmp(len,b1,b2) == 0)
		return 0;

	 /* START COMPARAING BYTES */
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

/* THIS FUNCTION FOR USER THAT USE my_bcmp FROM main WITHOUT USE getinput FILE */ 
int valid_bcmp (size_t len,const void *b1,const void *b2)
{
	int strl1=strlen(b1),strl2=strlen(b2);

	/* CHECK 0 STR */
	if ((strl1 <= 0) || (strl1 <= 0)){
		printf("\n\t( NOTE: STR NULL DEFAULT RETURN 0 )\n");
		return 0;
	}

	/* CHECK 0 LEN */
	if (len == 0){
		printf("\n\t( NOTE: LEN 0 DEFAULT RETURN 0 )\n");
		return 0;
	}
	
	/* CHECK LEN NEGATIVE */
	if ((int)len < 0){
		printf("\n\t ERROR: LEN = %d CAN'T BE NEGATIVE!\n", (int)len);
		exit(0);
	}

	/* CHECK LEN BIGGER FROM SIZE */
	if (len > SIZE){
		printf("\n\t ERROR: LEN CAN'T BE BIGGER THEN %d!\n", SIZE);
		exit(0);
	}

	/* CHECK LEN -> INDEX EXCEPTION */
	if (len > strl1 || len > strl2){
		printf("\n\tEXIT: LEN MAKE TO -> INDEX EXCEPTION\n");
		exit(0);
	}

return 1;
}
