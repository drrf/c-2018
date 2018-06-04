/*
 *          File: set.h
 *        Author: Ron F. <>
 * Last Modified: June 04, 2018
 *         Topic: Read commands from input & save and use data
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>   
#include <limits.h>   /* MB_LEN_MAX */
#include <string.h>   /* strlen, strtok, memset */
#include <ctype.h>    /* isspace */

#define SIZE 128	  /* SIZE OF SET */
#define LINE 128	  /* SIZE OF ENTER LINE */
#define ONE 1 		  /* USE IN FUNC THAT NEED 1 SET */
#define THREE 3 	  /* USE IN FUNC THAT NEED 3 SETS */	  
#define NSET 6        /* NUMBERS OF SET WE USE */
#define BLOCK -1	  /* FOR EMPTY SET */
#define READ_SET -1   /* SPECIAL NUMBER TO DETECTION read_set CMD */
#define FOREVER for (;;) /* FOREVER LOOP */

/* TEMP? */
#define ROW 10
#define COL 50


/* THE SET TYPEDEF, SIZE OF SET = 16 BIT */
typedef struct Sets {
	char n [MB_LEN_MAX]; /* NUMBER [0... 127] */
} set;

/* ARRAY OF POINTER TO SETS */
void *pSet[2];

/* CMD & SET FUNCTION ON FILE set.c */
void print_set(set *);
void read_set(set *,int *);
void intersect_set(set *,set *,set *);
void sub_set(set *,set *,set *);
void union_set(set *,set *,set *);
void stop(void);
void reset_set_block(set *,set *,set *);
void reset_set (set *);

/* FUNCTION ON FILE func.c */
void command(char[]);
int check_line(char[],char[]);
int check_sets(char[],int);
int check_comma (char[]);
int * read_check_nums(char[]);
void readset (char[]);
void pSet_cmd (int,int);
char * remove_2_white (char[]);
int space (char[]);				

/* ERR FUNCTION ON FILE err.c */
void cmd_err (void);
void cmd_comma_err(void);
void set_err (void);
void set_err_miss(void);
void set_extra_err(void);
void not_int (void);
void num_err (int);
void num_end_err (void);
void stop_by_eof (void);
void comma_err(int);
