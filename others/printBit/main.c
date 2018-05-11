/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: May 11, 2018
 *         Topic: Show number in binary
 * ----------------------------------------------------------------
 */
#include <stdio.h>

#define NEG_NUM     "\x1b[31m"
#define POS_NUM   "\x1b[32m"
#define RESET   "\x1b[0m"

/*

Max signed: 2147483647
Max unsigned: 4294967295

*/

void printBin(int);

int main () 
{
	int x;
	while (1)
	{
		printf("Enter a number: ");
		scanf("%d", &x);
		printBin(x);
		printf("\n");
	}
return 0;
}

void printBin(int x)
{
	unsigned int mask = 1 << (sizeof(int)* 8 - 1);
	if (x >= 0)
		printf(POS_NUM "BINARY: " RESET);
	else
		printf(NEG_NUM "BINARY: " RESET);
	
	while (mask)
	{
		if ((x&mask) == 0)
			printf("0");
		else
			printf("1");
		mask >>= 1;
	}
	printf("\n");
}
