#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "data.h"

/* CLEAN SCANF */
void clean_scanf(){
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
    	;
}

void valid_num(char c[]){
	int i;
	int len=strlen(c);

	if (c[0]=='-'){
		printf("CANT BE NEG NUMBER!\n");
		exit(0);
	}

	for (i=0; i<=len-1; i++){
		if (!isdigit(c[i])){
			printf("NOT VALID NUMBER!\n");
			exit(0);
		}	
	}
}

void valid_SIZE(int size){
	if (size > SIZE){
		printf("\n\t LEN CAN'T BE BIGGER THEN %d!\n", SIZE);
		exit(0);
	}
	if (size < 0){
		printf("\n\t LEN CAN'T BE SMALLER THEN 0!\n");
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
	if (b1+len > str_len-1 || b2+len > str_len-1){
		printf("\n\t *b1 or *b2 OUT FROM THE INDEX IN THIS CHECK!\n");
		exit(0);
	}
}
