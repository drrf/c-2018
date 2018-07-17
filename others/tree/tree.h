/*
 *          File: tree.h
 *        Author: Ron F. <>
 * Last Modified: July 1, 2018
 *         Topic: TREE (data structure)
 *          NOTE: My version to Self-referenaitl Structures
 *                from "THE C PROGRAMMING LANGUAGE 2nd edition" (p.139)
 * ----------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct tnode {      /* the tree node */
    char *word;          /* points to the text */
    int count;           /* number of occurrences */
    struct tnode *left;  /* left child */
    struct tnode *right; /* right child */
} tnode;


tnode *addtree (tnode *, char *);
void treeprint (tnode *);
tnode *talloc(void);
