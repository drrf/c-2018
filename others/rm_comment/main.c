/*
 *          File: main.c
 *        Author: Ron F. <>
 * Last Modified: April 3, 2018
 *         Topic: Comment remove from file
 * ----------------------------------------------------------------
 */

#include <stdio.h>

enum status{OUT,IN_STRING,LEFT_SLASH,IN_COMMENT,RIGHT_STAR,IN_CPP_COM};

int main() {
	int c;
	int state=OUT;

	while((c=getchar()!=EOF)){
		switch (state) {
			case OUT :
				if (c=='/')
					state = LEFT_SLASH;
				else {
					putchar(c);
					if(c=='\"')
						state=IN_STRING;
				}
				break;
			
			case LEFT_SLASH :
				if(c=='*')
					state=IN_COMMENT;
				else if(c=='/')
					state=IN_CPP_COM;
				else {
					putchar('/');
					putchar(c);
					state=OUT;
				}
				break;
			
			case IN_COMMENT :
				if(c=='*')
					state=RIGHT_STAR;
			break;
			
			case IN_CPP_COM :
				if(c=='\n'){
					state=OUT;
					putchar('\n');
				}
			break;
			
			case RIGHT_STAR :
				if(c=='/')
					state=OUT;
				else if(c!='*')
					state=IN_COMMENT;
			break;
			
			case IN_STRING :
				if(c=='\"')
					state=OUT;
				putchar(c);
			break;
		}
	}
	
	printf("\nThe file is ready!\n");

	return 0;
}
