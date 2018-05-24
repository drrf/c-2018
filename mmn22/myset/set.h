/*
 *          File: set.h
 *        Author: Ron F. <>
 * Last Modified: May 23, 2018
 *         Topic: ???
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strlen, strtok, memset */
#include <ctype.h>  /* isspace */

#define SIZE 128
#define LINE 128
#define NSET 6        /* NUMBERS OF SET WE USE */
#define PSET 2        /* NUMBERS OF POINTER WE NEED */
#define A_TO_NUM 64   /* FIX SET TO THE RIGHT NUMBER */
#define A_SET 65      /* THE SMALL SET */
#define Z_SET 70      /* THE BIG SET */
#define READ_SET -1   /* SPECIAL NUMBER TO DETECTION */
#define BLOCK -1
#define END -1
#define FOREVER for (;;)

/* COLOR */
#define ERR     "\x1b[31m"
#define POS_NUM   "\x1b[32m"
#define RST   "\x1b[0m"

/* TEMP? */
#define ROW 10
#define COL 50

enum {NO,YES};




typedef struct Sets {
	char n [SIZE]; /* NUMBER [0... 127] */
} set;

/* DO: MAKE ALL THE CMD VOID? */
void print_set(set *);
void read_set(set *,int *);
void intersect_set(set *,set *,set *);
void sub_set(set *,set *,set *);
void union_set(set *,set *,set *);
void stop(void);
void reset_set_block (set *s);

/* OTHER FUNC THE IMPORTANT */
int space (char[]);
char * remove_2_white (char[]);
void command(char[]);
int check_line(char[],char[]);
int check_sets(char[],int);
int check_comma (char[]);
int * read_check_nums(char[]);

void pSet_cmd (int,int,...);

void printset (char[]);
void readset (char[]);

/* ERR FUNC */
void cmd_err (void);
void cmd_comma_err(void);
void set_err (void);
void set_err_miss(void);
void set_extra_err(void);
void num_err (int);
void num_end_err (int);
void stop_by_eof (void);
void comma_err(int);
