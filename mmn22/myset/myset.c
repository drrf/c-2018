/*
 *          File: myset.h
 *        Author: Ron F. <>
 * Last Modified: June 04, 2018
 *         Topic: Read commands from input & save and use data
 * ----------------------------------------------------------------
 */

#include "set.h"

/* CREATE THE SET DATA */
set SETA, SETB, SETC, SETD, SETE, SETF;


/* LINE & LINE POINTER */
char str [LINE];
char * strP;

int main () {
/* EMPTY SETS SETTING */
SETA.n[0] = '\0';
SETB.n[0] = '\0';
SETC.n[0] = '\0';
SETD.n[0] = '\0';
SETE.n[0] = '\0';
SETF.n[0] = '\0';

FOREVER {
	printf("> ");
	while( !fgets (str, LINE, stdin) )
		stop_by_eof(); /* STOP IF EOF */

	/* PRINT TO SCREEN */
	printf("%s", str);

	/* REMOVE DOUBLE WHITE */
	strP = remove_2_white(str);

	command(strP);

	} /* FOREVER END */

return 0;
}

/* CHECK VALID COMMAND */
void command(char str [LINE])
{

/* REMOVE WHITE BLANK & ENTER THE FIRST LETTER */
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

/* CMD STOP */
if (!strcmp(str, stop_s))
	stop();

/* SWITCH BETWEEN THE CMD */
switch(c) {
      case 'i' :
	if ((i = check_line(str+i,inter_s)) > 0){
	  if(check_sets(str+i,THREE) == THREE)
          	intersect_set(pSet[0],pSet[1],pSet[2]);
	  }
         break;
      case 'p' :
	 if ((i = check_line(str+i,print_s)) > 0){
	   if(check_sets(str+i,ONE) == ONE)
	   	print_set(pSet[0]);
	   }
         break;
      case 'r' :
	if ((i = check_line(str+i,read_s)) > 0){
	  if(check_sets(str+i,READ_SET) == ONE);
	}
         break;
      case 's' :
	if ((i = check_line(str+i,sub_s)) > 0){
	  if(check_sets(str+i,THREE) == THREE)
          	sub_set(pSet[0],pSet[1],pSet[2]);
	  }
         break;
      case 'u' :
	 if ((i = check_line(str+i,uni_s)) > 0){
	  if(check_sets(str+i,THREE) == THREE)
          	union_set(pSet[0],pSet[1],pSet[2]);
	  }
         break;
      default :
	 cmd_err();
   } /* END OF SWITCH */
}

/* MOVE THE POINTER TO SET */
void pSet_cmd (int set,int i)
{
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


