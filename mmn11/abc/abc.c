/*
 *          File: abc.c
 *        Author: Ron F. <>
 * Last Modified: April 8, 2018
 *         Topic: Found sequence
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <ctype.h>
#include "data.h"

void abc (char str[SIZE]) {
	int state=OUT;
	int i, start, end, count;

	for (i = 0; str[i] != '\0'; ++i) {
		switch (state) {
			case OUT :
				if (isalpha(str[i]) && str[i]+1 == str[i+1]){
					start = i+1;
					++count;
					state = IN;
				} else {
					count = 0;
					start = 0;
				}
				break;
			
			case IN :
				if (str[i]+1 == str[i+1]) {
					++count;
					if (count >= ABC)
						state = FOUND;
				} else { 
					count = 0;
					start = 0;
					state = OUT;
				}
				break;

			case FOUND :
					/* FOUND THE END OF ABC SEQUENCE */
					for(end=start+1; str[end]+1 == str[end+1]; ++end)
					;

					str[start] = '-';	
					str[start+1] = str[end];

					/* FIX THE STRING */
					for (i=start+HYPHEN+1; str[i] != '\0'; ++i) {
						str[i] = str[end+1];
						++end;
					}

					/* REPOSITION i TO THE FIXED STRING */
					i = start+HYPHEN;

				state = OUT;
				break;
		} /* END OF SWITCH */
		
	}
	/* OUTPUT PRINT */
	printf("\n----------------------------------------\n");
	printf("The sequences in this string fixed to: %s",str);
	printf("----------------------------------------\n");

}
