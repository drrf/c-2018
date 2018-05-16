/*
 *          File: myset.h
 *        Author: Ron F. <>
 * Last Modified: May 8, 2018
 *         Topic: ???
 * ----------------------------------------------------------------
 */

#include "set.h"

/* CREATE THE DATA */
set SETA, SETB, SETC, SETD, SETE, SETF;

/* POINTER TO SET */
void *pSet;

struct {
	char *name;
	void (*func)(void);
	} cmd[] = {
		/* {"read_set",read_set},
		{"print_set",print_set}, */
		{"stop",stop}
	};

int main () {
char str [LINE];

/* EMPTY SETS SETTING */
	SETA.n[0] = EMPTY;
	SETB.n[0] = EMPTY;
	SETC.n[0] = EMPTY;
	SETD.n[0] = EMPTY;
	SETE.n[0] = EMPTY;
	SETF.n[0] = EMPTY;

FOREVER {
	printf("> ");
	fgets(str, LINE, stdin);
	command(str);
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
char a[ROW][COL] = {
	/* a[0] */ "intersect_set",
	/* a[1] */ "print_set",
	/* a[2] */ "read_set",
	/* a[3] */ "stop",
	/* a[4] */ "sub_set",
	/* a[5] */ "union_set",
};
char *inter_s   = a[0];
char *print_s   = a[1];
char *read_s    = a[2];
char *stop_s    = a[3];
char *sub_s     = a[4];
char *union_s   = a[5];

/* printf("STR = %s\n", str); */

switch(c) {
      case 'i' :
	if (check_line(str,inter_s)){
           printf("intersect_set?\n");
	} else {
	   cmd_err();
	}
         break;
      case 'p' :
	 if (check_line(str,print_s)){
	   printset(str);
	} else {
	   cmd_err();
	}
         break;
      case 'r' :
	if (check_line(str,read_s)){
	   readset(str);
	   /*pSet = &SETA;
           read_set(pSet);*/
	} else {
	   cmd_err();
	}
         break;
      case 's' :
	 if (check_line(str,stop_s)){
	  stop();
	} else if (check_line(str,sub_s)){
          printf("sub_set?\n");
	} else {
	  cmd_err();
	}
         break;
      case 'u' :
	 if (check_line(str,union_s)){
           printf("union_set?\n");
	} else {
	   cmd_err();
	}
         break;
      default :
	 cmd_err();
   } /* END OF SWITCH */


}

void printset (char str[])
{
	int count_set = check_sets(str);
	
	if (count_set == 1){
		print_set(pSet);
	} else {
		set_err();
	}
}

void readset (char str[])
{
	int count_set = check_sets(str);
	int * nums;

	/* RETUEN ARRAY OF NUMBERS */
	nums = read_check_nums(str);
	if (count_set == 1){
		if (nums[0]!=EMPTY)
           	read_set(pSet,nums);
	}
	else
		set_err();
}

/* MOVE THE POINTER TO SET */
void pSet_cmd (int a,...)
{
/* HOW TO ADD MORE POINTER SET ON THIS FUNC? */
switch(a) {
      case 1 :
	pSet = &SETA;
         break;
      case 2 :
	pSet = &SETB;
         break;
      case 3 :
	pSet = &SETC;
         break;
      case 4 :
	pSet = &SETD;
         break;
      case 5 :
	pSet = &SETE;
         break;
      case 6 :
	pSet = &SETF;
         break;
      default :
	 printf("ERROR: WITH SET POINTER!\n");
   } /* END OF SWITCH */
}


