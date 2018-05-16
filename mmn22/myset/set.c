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
	if ((int)S.n[0]==EMPTY){
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
	(*s).n[0] = '0';

	for (i=0;i<=SIZE;i++){
		copy = *(nums + i);
		if (copy == -1)
			break;
		else
		(*s).n[copy] = (char)copy;
	}

	/* TESTING CODE
	printf("sata = %p\n", &(*s));
	print_set(s); */
}

/* SUB */ 
void sub_set (set s1, set s2, set s3)
{
	printf("sub commend not ready yet\n");
}

/* UNION */ 
void union_set (set s1, set s2, set s3)
{
	printf("union commend not ready yet\n");
}