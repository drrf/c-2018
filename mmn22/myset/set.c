/*
 *          File: set.c
 *        Author: Ron F. <>
 * Last Modified: June 04, 2018
 *         Topic: Read commands from input & save and use data
 * ----------------------------------------------------------------
 */

#include "set.h"
#define SIZE_16 MB_LEN_MAX

/* STOP THE PROGRAM */ 
void stop()
{
	printf("GOODBYE FREIND!\n");
	exit(0);
}

/* PRINT THE OPEN BIT IN THE SET */ 
void print_set(set *s)
{
set S = *s;
int i=0,num=1,mask=1,maskL=8,first=0,count=0;

while (i < SIZE_16){
	while (maskL--){ /* LOOP FOR MASK LENGTH OF CHAR 00000000  */
		if ((mask&S.n[i]) != 0){
			if (first == 1){
				printf(", ");
			}
			if (num < SIZE){ /* FOR UNIDENTIFIED SMALL BUG */
				printf("%d", num);
				first = 1;
				count++;
			}
		}
		mask <<=1; /* EQUAL TO mask*2 */
		num++;
	}

	/* RESET & MOVE TO NEXT CELL 1/16 */
	i++;
	mask=1;
	maskL=8;
} /* END OF WHILE */
if (count == 0)
	printf("\nThis set is empty\n");
else
	printf("\n");
}

/* WRITE BIT IN THE SET */ 
void read_set(set *s, int * nums)
{
unsigned int mask = 1;
int bit = 0;
int i = 0;
int cell = 0;

/* RESET & REMOVE -1 BLOCK */
reset_set(s);

while (nums[i] != -1)
	{
	/* FIX THE % = 0 PROBLEM IN 8 MULTIPLY */
	if (nums[i] % 8 == 0)
		cell = ((nums[i] / 8) -1);
	else
		cell = (nums[i] / 8);

	bit = nums[i] % 8;

	/* IF ITS 0 ITS MEAN WE HAVE 8 THERE */
	if (bit > 0)
		(*s).n[cell] += (mask << (bit-1));
	else
		(*s).n[cell] += 128; 
	i++;
	} /* END OF WHILE */
}

/* ADD ONLY BIT THAT BOTH IN SET1 & SET2, TO SET3  */
void intersect_set (set *s1, set *s2, set *s3)
{
	int i;

	for (i=0; i<SIZE_16; i++){
		(*s3).n[i] = (*s1).n[i] & (*s2).n[i];
	}
}


/* ADD ONLY BIT THAT APPEAR ONLY IN SET1, TO SET3 */ 
void sub_set (set *s1, set *s2, set *s3)
{
	int i;

	for (i=0; i<SIZE_16; i++){
		(*s3).n[i] = (*s1).n[i] & (*s2).n[i]; /* ADD 1 & 1 */
		(*s3).n[i] ^= (*s1).n[i];			  /* ADD 0 ^ 1, DEL 1 ^ 1 */
	}
}

/* ADD BIT THAT APPEAR IN SET1 & SET2, TO SET3 */ 
void union_set (set *s1, set *s2, set *s3)
{
	int i;

		for (i=0; i<SIZE_16; i++)
			(*s3).n[i] = (*s1).n[i] | (*s2).n[i];
}

/* RESET SET FOR REWRITE */
void reset_set (set *s)
{
	int i;

	for (i = 0; i < SIZE_16; i++)
		(*s).n[i] = '\0';
}

