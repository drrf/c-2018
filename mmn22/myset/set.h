/*
 *          File: set.h
 *        Author: Ron F. <>
 * Last Modified: May 8, 2018
 *         Topic: ???
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strlen, strtok, memset */
#include <ctype.h> /* isspace */

#define SIZE 128
#define LINE 128
#define EMPTY -1
#define FOREVER for (;;)

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
void stop(void);

/* OTHER FUNC THE IMPORTANT */
int space (char str[]);
void command(char[]);
int check_line(char[],char[]);
int check_sets(char[]);
int * read_check_nums(char[]);

void pSet_cmd (int,...);

void printset (char[]);
void readset (char[]);

/* ERR FUNC */
void cmd_err (void);
void set_err (void);
void num_err (int);

