/*
 *          File: getinput.c
 *        Author: Ron F. <>
 * Last Modified: April 25, 2018
 *         Topic: Comparing bytes of to pointer
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stddef.h> /* for size_t */
#include <string.h> /* for strlen */
#include <stdlib.h> /* for atof */
#include "data.h"
#define MAXCHAR 2

void clean_scanf();
void valid_num(char c[]);
void valid_SIZE(int s);
void valid_SIZE_2(int s1,int s2);
void valid_SIZE_3(int s1,int s2,int s3);
void valid_SIZE_4(int s1,int s2,int s3,int s4);
void printinput(int len,int b1,int b2, char s[]);
int my_bcmp (const void *b1, const void *b2, size_t len);

int getinput(){
	char str[SIZE];
	char *b1, *b2;
	size_t len;
	int bb1, bb2;
	char ch1[MAXCHAR];
	char ch2[MAXCHAR];

	printf("\n\t Enter the length of bytes to check: ");
	scanf("%s", ch1);
	valid_num(ch1);
	len=atof(ch1);

	/* START valid FILE */
	clean_scanf();
	valid_SIZE(len);

	printf("\n\t Enter a b1 and b2 loc on the string: ");
	scanf("%s%s", ch1,ch2);

	/* START valid FILE */
	valid_num(ch1);
	valid_num(ch2);
	bb1=atof(ch1);
	bb2=atof(ch2);
	clean_scanf();
	valid_SIZE_2(bb1,bb2);

	printf("\n\t Enter a string (max %d char): ",SIZE);
	fgets(str, SIZE, stdin);

	/* START valid FILE */
	valid_SIZE_3(bb1,bb2,strlen(str));
	valid_SIZE_4(bb1,bb2,strlen(str),len);

	/* SET THE POINTER */
	b1 = &str[bb1];
	b2 = &str[bb2];

	/* START printinput FILE */
	printinput(len,bb1,bb2,str);

	/* START my_bcmp FILE */
	return my_bcmp(b1,b2,len); 
}


