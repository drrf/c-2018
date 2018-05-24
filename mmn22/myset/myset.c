/*
 *          File: myset.h
 *        Author: Ron F. <>
 * Last Modified: May 23, 2018
 *         Topic: ???
 * ----------------------------------------------------------------
 */

#include "set.h"

/* CREATE THE DATA */
set SETA, SETB, SETC, SETD, SETE, SETF;

/* POINTER TO SET 
void *pSet; */

void *pSet[PSET];

int main () {
char str [LINE];
char * str2;
/* EMPTY SETS SETTING */
	SETA.n[0] = BLOCK;
	SETB.n[0] = BLOCK;
	SETC.n[0] = BLOCK;
	SETD.n[0] = BLOCK;
	SETE.n[0] = BLOCK;
	SETF.n[0] = BLOCK;

FOREVER {
	printf("> ");
	while(!fgets(str, LINE, stdin))
		stop_by_eof();
	printf("%s", str);
	str2 = remove_2_white(str);
	/* printf("> %s \n",str2);*/
	command(str2);

	/* FREE STR2 FROM remove_2_white */
	free(str2); 
	} /* FOREVER END */
return 0;
}

/* CHECK VALID COMMAND */
void command(char str [LINE])
{

/* REMOVE WHITE BLANK */
int i = space(str);
char c = str[i];


/* NEXT: MAKE POINTER TO ARRAY STRING */
char abc[ROW][COL] = {
	/* a[0] */ "intersect_set",
	/* a[1] */ "print_set",
	/* a[2] */ "read_set",
	/* a[3] */ "stop",
	/* a[4] */ "sub_set",
	/* a[5] */ "union_set",
};
char *inter_s   = abc[0];
char *print_s   = abc[1];
char *read_s    = abc[2];
char *stop_s    = abc[3];
char *sub_s     = abc[4];
char *uni_s     = abc[5];

/* printf("STR = %s\n", str); 
printf("i=%d,c=%c", i,c); */


if (!strcmp(str, stop_s))
	stop();


switch(c) {
      case 'i' :
	if ((i = check_line(str+i,inter_s)) > 0){
	  if(check_sets(str+i,3) == 3)
          	intersect_set(pSet[0],pSet[1],pSet[2]);
	  }
         break;
      case 'p' :
	 if ((i = check_line(str+i,print_s)) > 0){
	   if(check_sets(str+i,1) == 1)
	   	print_set(pSet[0]);
	   }
         break;
      case 'r' :
	if ((i = check_line(str+i,read_s)) > 0){
	  if(check_sets(str+i,READ_SET) == 1)
		readset(str);
	}
         break;
      case 's' :
	if ((i = check_line(str+i,sub_s)) > 0){
	  if(check_sets(str+i,3) == 3)
          	sub_set(pSet[0],pSet[1],pSet[2]);
	  }
         break;
      case 'u' :
	 if ((i = check_line(str+i,uni_s)) > 0){
	  if(check_sets(str+i,3) == 3)
          	union_set(pSet[0],pSet[1],pSet[2]);
	  }
         break;
      default :
	 cmd_err();
   } /* END OF SWITCH */


}

void printset (char str[])
{
	int count_set = check_sets(str,1);
	
	if (count_set == 1){
		print_set(pSet[0]);
	} else {
		set_err();
	}
}

void readset (char str[])
{
	int * nums;

	/* RETUEN ARRAY OF NUMBERS */
	nums = read_check_nums(str);

	if (nums[0]!=BLOCK)
        	read_set(pSet[0],nums);
}

/* MOVE THE POINTER TO SET */
void pSet_cmd (int set,int i,...)
{
/* HOW TO ADD MORE POINTER SET ON THIS FUNC? */
switch(set) {
      case 1 :
	pSet[i] = &SETA;
         break;
      case 2 :
	pSet[i] = &SETB;
         break;
      case 3 :
	pSet[i] = &SETC;
         break;
      case 4 :
	pSet[i] = &SETD;
         break;
      case 5 :
	pSet[i] = &SETE;
         break;
      case 6 :
	pSet[i] = &SETF;
         break;
      default :
	 printf("ERROR: WITH SET POINTER!\n");
   } /* END OF SWITCH */
}


