/*
 *          File: set.c
 *        Author: Ron F. <>
 * Last Modified: May 8, 2018
 *         Topic: ???
 * ----------------------------------------------------------------
 */

#include "set.h"

/* STOP TO PROGRAM */ 
void stop()
{
	printf("GOODBYE FREIND!\n");
	exit(0);
}

/* PRINT */ 
void print_set(set *s)
{
	set S = *s;
	int i,first=0;
	if ((int)S.n[0]==BLOCK){
		printf("\nThis set is empty\n");
		return;
	} else {
		for(i=1;i<=SIZE-1;i++){
			if (S.n[i]!=0){
			if (first == 1){
				printf(", ");	
			}
			printf("%d", i /* (int)S.n[i]*/);
			first = 1;
			}
		}	
	}
	printf("\n");
}

void read_set(set *s, int * nums)
{
	int copy, i;
	/* REMOVE -1 BLOCK */
	reset_set_block(s);

	for (i=0;i<=SIZE;i++){
		copy = *(nums + i);
		if (copy == -1)
			break;
		else
		(*s).n[copy] = (char)copy;
	}
}

void intersect_set (set *s1, set *s2, set *s3)
{
	int i;

	for (i=0; i<SIZE; i++){
		(*s3).n[i] = (*s1).n[i] & (*s2).n[i];
	}

	/* REMOVE -1 BLOCK */
	reset_set_block(s3);
}


/* SUB */ 
void sub_set (set *s1, set *s2, set *s3)
{
	int i;

	for (i=0; i<SIZE; i++){
		(*s3).n[i] = (*s1).n[i] ^ (*s2).n[i];
	}

	/* REMOVE -1 BLOCK */
	reset_set_block(s3);
}

/* UNION */ 
void union_set (set *s1, set *s2, set *s3)
{
	int i;

	for (i=0; i<SIZE; i++){
		(*s3).n[i] = (*s1).n[i] | (*s2).n[i];
	}

	/* REMOVE -1 BLOCK */
	reset_set_block(s3);

}

/* RESET THE FIRST CELL FOR OPEN PRINT */
void reset_set_block (set *s)
{
	(*s).n[0] = '0';
}
