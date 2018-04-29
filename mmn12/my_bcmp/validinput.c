/*
 *          File: valid.c
 *        Author: Ron F. <>
 * Last Modified: April 26, 2018
 *         Topic: Comparing bytes from two pointers
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h> /* for exit, atoi */
#include <string.h> /* for strlen */
#include <ctype.h>  /* for isdigit */
#include "data.h"

void clean_scanf(){
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
    	;
}

int valid_num(char c[]){
	int i;
	int len=strlen(c);

	if (c[0]=='-'){
		printf("\n\t ERROR: CAN'T ENTER NEGATIVE NUMBER!\n");
		exit(0);
	}

	for (i=0; i<=len-1; i++){
		if (!isdigit(c[i])){
			printf("\n\t ERROR: PLEASE ENTER ONLY A FULL DECIMAL NUMBER!\n");
			exit(0);
		}	
	}

	return atoi(c);
}

void valid_SIZE(int size){
	if (size > SIZE){
		printf("\n\t ERROR: LEN CAN'T BE BIGGER THEN %d!\n", SIZE);
		exit(0);
	}
}

void valid_SIZE_2(int size1, int size2){
	if (size1 > SIZE || size2 > SIZE){
		printf("\n\t *b1 or *b2 CAN'T BE BIGGER THEN %d!\n", SIZE);
		exit(0);
	}
	if (size1 < 0 || size2 < 0){
		printf("\n\t *b1 or *b2 CAN'T BE SMALLER THEN 0!\n");
		exit(0);
	}
}

void valid_SIZE_3(int size1,int size2,int len_str){
if (size1 > len_str || size2 > len_str){
		printf("\n\t *b1 or *b2 INDEX CAN'T BE BIGGER FROM STR!\n");
		exit(0);
	}
}

void valid_SIZE_4(int b1,int b2,int str_len,int len){
	if (b1+len > str_len || b2+len > str_len){
		printf("\n\t *b1 or *b2 OUT FROM THE INDEX IN THIS CHECK!\n");
		exit(0);
	}
}
