/*
 *          File: getinput.c
 *        Author: Ron F. <>
 * Last Modified: April 29, 2018
 *         Topic: Comparing bytes from two pointers
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stddef.h> /* for size_t */
#include <string.h> /* for strlen */
#include "data.h"  /* for my_bcmp */
#define MAXCHAR 2

void clean_scanf();
int valid_num(char[]);
void valid_SIZE(int);
void valid_SIZE_2(int,int);
void valid_SIZE_3(int,int,int);
void valid_SIZE_4(int,int,int,int);
void printinput(int,int,int,char[]);

int getinput(){
	char str[SIZE];
	char *b1, *b2;
	size_t len;
	int p1, p2;
	char ch1[MAXCHAR];
	char ch2[MAXCHAR];

	printf("\n\t Enter the length of bytes to check: ");
	scanf("%s", ch1);

	/* START valid FILE */
	len=valid_num(ch1);
	clean_scanf();
	valid_SIZE(len);

	printf("\n\t Enter a b1 and b2 loc on the string: ");
	scanf("%s%s", ch1,ch2);

	/* START valid FILE */
	p1=valid_num(ch1);
	p2=valid_num(ch2);
	clean_scanf();
	valid_SIZE_2(p1,p2);

	printf("\n\t Enter a string (max %d char): ",SIZE);
	fgets(str, SIZE, stdin);

	/* START valid FILE */
	valid_SIZE_3(p1,p2,strlen(str));
	valid_SIZE_4(p1,p2,strlen(str),len);

	/* SET THE POINTER */
	b1 = &str[p1];
	b2 = &str[p2];

	/* START printinput FILE */
	printinput(len,p1,p2,str);

	/* START my_bcmp FILE */
	return my_bcmp(b1,b2,len); 
}


