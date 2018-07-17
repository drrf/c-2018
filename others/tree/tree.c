/*
 *          File: tree.c
 *        Author: Ron F. <>
 * Last Modified: July 1, 2018
 *         Topic: TREE (data structure)
 *          NOTE: My version to Self-referenaitl Structures
 *                from "THE C PROGRAMMING LANGUAGE 2nd edition" (p.139)
 * ----------------------------------------------------------------
 */

#include "tree.h"

/* word frequncy count */
int main ()
{
    tnode *root;
    char str [] = "now is the time for all the good men to come to the aid of their party";
    const char s[2] = " ";
    char *token;
    
    token = strtok(str, s);
    root = NULL;

    printf("Tree program!\n");

    while( token != NULL ) {
        root = addtree(root, token);
        token = strtok(NULL, s);
   }
    treeprint(root);

    return 0;
}

/* addtree: add a node with w at or below p */
tnode *addtree (tnode *p, char *w)
{
    int cond;

    if (p == NULL) {    /* a new word has arrived */
        p = talloc();   /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p-> left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;     /* repeated word */
    else if (cond < 0)  /* less than into left subtree */
        p->left = addtree(p->left, w);
    else                /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
tnode *talloc(void)
{
    return (tnode *) malloc(sizeof(tnode));
}
