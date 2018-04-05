/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: April 3, 2018
 *         Topic: Write and Copy from file1 to file2
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <time.h>
#define SIZE 100

int main() {
	time_t t;
	time(&t);
	char fileN[SIZE];
	char copy[SIZE];
	FILE *pFileW;
	FILE *pFileR;

	printf("Enter name of new file: ");
	scanf("%s", fileN);
	
	/* OPEN THE FILE WITH READ */
	pFileR = fopen("file1.txt","r");

	/* OPEN THE FILE WITH WRITE */
	pFileW = fopen(fileN,"w");
	
	if (pFileR != NULL)
	{
		printf("Looking in file1...\n");
		/* COPY LINE FROM FILE */
		fgets(copy, SIZE, pFileR); 
		fprintf(pFileW, "%s", ctime(&t));
		fprintf(pFileW, "%s", copy);
		printf("COPY: %s", copy);
		printf("COPY TO: \"%s\" on %s", fileN,ctime(&t));

	}
	else
	{
		printf("Could not open the file.\n");
	}

	if (pFileW != NULL)
	{
		
		fprintf(pFileW, "This is the info age.\n");
		printf("Success create and copy to file \"%s\".\n" ,fileN);
		
	}
	else
	{
		printf("Could not open the file.\n");
	}

	
	/* OPEN THE FILE AND READ */
	fclose(pFileR);
	fclose(pFileW);
	return 0;
}
