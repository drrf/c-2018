/*
 *          File: valid.c
 *        Author: Ron F. <>
 * Last Modified: April 8, 2018
 *         Topic: Found sequence
 * ----------------------------------------------------------------
 */

#include "data.h"

int valid (int check) {
	if (check < up_case_start){
		return OUT;
	} else if (check > low_case_end) {
		return OUT;
	} else {
		return FOUND;
	}
}
