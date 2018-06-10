/*
 *          File: permut.c
 *        Author: Ron F. <>
 * Last Modified: June 04, 2018
 *         Topic: Get arguments from command line and found permutation in file text
 * ----------------------------------------------------------------
 */

#include <stdio.h>		/* FILE FUNCTION */
#include <stdlib.h>		/* ALLOCATED MEMORY */
#include <string.h>		/* STRLEN */

void printP (char[],int);
int readF (char[],char[]);

int main (int argc, char *argv[])
{
const int ARGE = 3; 			/* ARG EXPECT FROM argc */
char * FileN = argv[1];			/* FILE NAME */
char * PermutN = argv[2];		/* PERMUTATION NAME */
FILE * fp = fopen (FileN,"r");	/* POINTER TO FILE */
int Flen = 0;					/* FILE LENGTH IN BYTES */
char * FileC = (char *) malloc(Flen);   /* ARRAY FOR COPY FILE CONTENT */

if (argc == ARGE){		/* IF argc IS THE SOME AS EXPECT */
	if( fp==NULL ) {	/* IF DON'T FOUND THE FILE */
		fprintf(stderr, "Can't open the file!\n");
	} else {
		fseek (fp, 0, SEEK_END);
		Flen = ftell(fp);
		rewind(fp);
		if (Flen == 0) { /* IF  FILE IS EMPTY */
			fprintf(stderr, "File '%s' is empty!\n",FileN);
		} else {
			int c=0, i=0;
			FileC = (char *) realloc(FileC,Flen);
			while (1) { /* COPY FILE CONTENT TO ARRAY */
				c = fgetc(fp);
				if ( feof (fp) ){
					break;
				}
				FileC[i++] = (char)c;
			} /* END OF WHILE */
				if (readF(FileC,PermutN) == 0) /* START FOUND PERMUTATION */
					printf("FOUND: 0 PERMUT IN THE FILE!\n");
				fclose(fp);
				free(FileC);
		}
	}
} else {
	fprintf(stderr, "Missing %d argc \n", ARGE-argc);
}

return 0;
}



/* READ FILE CONTENT AND FOUND PERMUT */
int readF(char buf [],char A[])
{
int i=0,j=0,B_LEN=strlen(buf),A_LEN=strlen(A),Sum=0,Sum_OF_A=0,TIME=0,FOUND=0;

/* GET THE SUM OF A */
for (i=0; i<A_LEN; i++)
	Sum_OF_A += A[i];

for (i = 0; i < B_LEN; i++){
	for (j=0; j < A_LEN; j++){
		TIME++;
		if (buf [i] == A [j]){ /* FOUND MATCH */
			Sum += buf [i++]; 
			j = -1;		
		}
		if (Sum == Sum_OF_A){
			printP(buf+(i-A_LEN),A_LEN);
			FOUND++;
			TIME = 0;
			Sum = 0;
		}
	}
	if (TIME > A_LEN || Sum > Sum_OF_A){ /* RESET OVER USE */
		Sum = 0;
		TIME = 0;
	}
} /* END OF FOR */
return FOUND;
}

/* PRINT PERMUT */
void printP (char A[], int len)
{
int i=0;

for (i=0; i<len; i++){
	printf("%c", A[i]);
}
	puts("");
}
