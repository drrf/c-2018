/*
 *          File: r1.c
 *        Author: Ron F. <>
 * Last Modified: April 8, 2018
 *         Topic: asmbler
 * ----------------------------------------------------------------
 */

#include "myas.h"
#define WORD_IN_ARR 5 /* IN ARRAY OF ONE LINE CAN BE MAX OF 5 WORDS */

#define EN ".entry"
#define EX ".extern"
#define DATA ".data"
// #define STRING ".string"

/* COPY LINE TO STRING, BREAK TO WORD, CHECK FOR ERR AND SAVE DATA */
int breakToWords (SLine S, char FileArr[S.SLen])
{
    int ERR = 0, LABEL = 0, POINT = 0, D_POINT = 0, STRING = 0, QUOTA = 0;
    int IC=0, DC=0;
    int c, c_case = 0, i = 0, ind = 0, len = 0, cpWord = 0, wordCunter = 0, sum = 0;
    char oneLine [MAX_LINE];
    char oneWord [MAX_WORD];
    int WordArr [MAX_WORD];
    
    for (i = 0; i < S.SLines-1; i++){
        strncpy(oneLine, FileArr+S.SLineArr[i], S.SLineArr[i+1]-1); /* -1 remove '\n' */
        oneLine[(S.SLineArr[i+1]-S.SLineArr[i]-1)] = '\0';          /* add EOF */
        len = strlen(oneLine);

        /* JUMP OVER COMMENT & EMPTY LINE */
        c = oneLine[ind];
        if (c == ';' || strlen(oneLine) < 1) continue;

        /* ERROR IN THE FIRST CHAR */
        if ( isdigit(c) || c == '\"' || c == ':' || c == ',' || c == '(' || c == ')' || c == '#' || c == '-' || c == '+' )
            pERR1st (ERR = TRUE,c,i+1);

        /* ERROR IN THE LAST CHAR */
        c = oneLine[len-1];
        if ( c == ':' || c == '#' || c == ',' || c == '+' || c == '-' )
            pERR1st (ERR = TRUE,c,i+1);

        /* CHECK FOR ERR AND CUT FOR WORDS */
        while (c = oneLine[ind++]){
            oneWord[cpWord++] = (char)c;
            if (isalpha(c))
                c_case = 1; /* A-Z && a-z */
            else if (isdigit(c))
                c_case = 2; /* 0-9 */
            else if (c == '.')
                c_case = 3;
            else if ( c == '-' || c == '+' || c == '#' )
                c_case = 4;
            else if ( c == ':' )
                c_case = 5;
            else if ( c == '(' || c == ')')
                c_case = 6;
            else if (c == '\"')
                c_case = 7;
            else if (c == ',')
                c_case = 8;
            else if (c == ' ' || c == '\n')
                c_case = 9;
            else
                c_case = 0;

            switch(c_case) {
                case 1 : //printf("ALPHA!\n" );
                    break;
                case 2 : //printf("DIGIT!\n" );
                    break;
                case 3 : //printf("POINT!\n" );
                    POINT++;
                    if (POINT > ONE && STRING == FALSE) pERRduble (c,i+1);
                    break;
                case 4 : //printf("NUMBER WORK!\n" );
                    if (wordCunter+FIRST == FIRST) pERR1st (ERR = TRUE,c,i+1);
                    break;
                case 5 : //printf("LABEL END!\n" );
                    D_POINT++;
                    if (D_POINT > ONE && STRING == FALSE) pERRduble (c,i+1);
                    break;
                case 6 :
                    if (wordCunter+FIRST == FIRST) pERR1st (ERR = TRUE,c,i+1);
                    break;
                case 7 : //printf("ARRAY OF STRING!\n" );
                    STRING++;
                    QUOTA++;
                    if (wordCunter+FIRST == FIRST) pERR1st (ERR = TRUE,c,i+1);
                    break;
                case 8 : //printf("ARRAY OF NUMBER!\n" );
                    if (wordCunter+FIRST == FIRST) pERR1st (ERR = TRUE,c,i+1);
                    break;
                case 9 : //printf("SPACE!\n" );
                    if (STRING == FALSE){
                        oneWord[cpWord-1] = '\0'; /* CLOSE ONE WORD */
                        printf("-> %s\n", oneWord );

                        if (ERR == FALSE)
                            sum = return_sum(wordCunter,oneWord,WordArr);
                        
                        if (sum == ERR_ENCODE){
                            pERRword(oneWord,i+1);
                            ERR = TRUE;
                        }

                        cpWord = 0;
                        wordCunter++;
                    }
                    break;
                default :
                    ERR = TRUE;
                    pERRchar (c,i+1);
            }
        }

        /* CHECK IF THERE IS START & END OF QUOTA */
        if (STRING >= ONE && QUOTA != TWO)
            pERRmiss (c,i+1);

        /* PRINT LAST WORD */
        oneWord[cpWord] = '\0'; 
        printf("%s <-\n", oneWord );

        /* ADD SUM TO LAST WORD */
        if (ERR == FALSE)
            sum = return_sum(wordCunter,oneWord,WordArr);

        if (sum == ERR_ENCODE){
            pERRword(oneWord,i+1);
            ERR = TRUE;
        }

        /* RESET TO NEXT TIME */
        ind = 0; cpWord = 0; wordCunter = 0;
        ERR = 0; LABEL = 0; POINT = 0; D_POINT = 0; STRING = 0;
        

        printf("%d) %s\n", i+1, oneLine);
        puts("");
    }

    printf("\n****************************************\n");
    printf("there is %d bytes in this array!\n", S.SLen);
    printf("there is %d lines in this array!\n", S.SLines-1); 
    printf("****************************************\n");

    puts("");

    return 0;
}

int return_sum (int wordCunter, char Str [MAX_WORD], int WordArr [WORD_IN_ARR])
{
    
    int len = strlen(Str);
    int ind = 0;

    /* MAJIC NUMBER TO ENCODING THE LINE  */
    int sum = ERR_ENCODE;
    int label = -100;
    int r = 114;
    int string = 2000;
    int digit = 1000;
    int psik = -1000;

    if (Str[0] == '.' && isalpha(Str[len-1])){
        sum = wordsToData(wordCunter,Str,WordArr);
    } else if (isdigit(Str[0]) || Str[0] == '#' || Str[0] == '-' || Str[0] == '+') {
        sum = WordArr[wordCunter] = digit;
    } else if (Str[0] == '\"' && Str[len-1] == '\"') {
        sum = WordArr[wordCunter] = string;
    } else if (isalpha(Str[0]) && Str[len-1] == ':') {
        sum = WordArr[wordCunter] = label;
    } else if (Str[0] == 'r' && isdigit(Str[1]) && len < 3 ) {
        sum = WordArr[wordCunter] = r;
    } else if (isalpha(Str[0]) && (isalpha(Str[len-1]) || isdigit(Str[len-1]))) {
        sum = wordsToOpt(wordCunter,Str,WordArr);
    } else if (Str[0] == ',') {
        sum = psik;
        return_sum(wordCunter,Str+1,WordArr); /* SKIP ON CHAR ',' */
    } else {
        sum = WordArr[wordCunter] = sum;
    }

    if (sum != psik){ /* this line is for don't see double print */
        for (ind = 0; ind <= wordCunter; ind++){
            printf("%d, ", WordArr[ind] );
        }
    }

    puts("");

    return sum;
}

int wordsToData (int num, char Str [MAX_WORD], int arr [WORD_IN_ARR] )
{
    char en[]       = ".entry";
    char ex[]       = ".extern";
    char data[]     = ".data";
    char string[]   = ".string";

    int sum = ERR_ENCODE;
    int ind = 0;

            if (strcmp(Str,en) == 0)
                sum = -99;
            else if (strcmp(Str,ex) == 0)
                sum = -999;
            else if (strcmp(Str,data) == 0)
                sum = -10;
            else if (strcmp(Str,string) == 0)
                sum = -15;
            else
                ;
    
    arr[num] = sum;

    puts("");

    return sum;
}

int wordsToOpt (int num, char Str [MAX_WORD], int arr [WORD_IN_ARR] )
{
    char mov[]      = "mov";
    char cmp[]      = "cmp";
    char add[]      = "add";
    char sub[]      = "sub";
    char not[]      = "not";
    char clr[]      = "clr";
    char lea[]      = "lea";
    char inc[]      = "inc";
    char dec[]      = "dec";
    char jmp[]      = "jmp";
    char bne[]      = "bne";
    char red[]      = "red";
    char prn[]      = "prn";
    char jsr[]      = "jsr";
    char rts[]      = "rts";
    char stop[]      = "stop";

    int sum = ERR_ENCODE;
    int ind = 0;

    if (strcmp(Str,mov) == 0)
        sum = mov_V;
    else if (strcmp(Str,cmp) == 0)
        sum = cmp_V;
    else if (strcmp(Str,add) == 0)
        sum = add_V;
    else if (strcmp(Str,sub) == 0)
        sum = sub_V;
    else if (strcmp(Str,not) == 0)
        sum = not_V;
    else if (strcmp(Str,clr) == 0)
        sum = clr_V;
    else if (strcmp(Str,lea) == 0)
        sum = lea_V;
    else if (strcmp(Str,inc) == 0)
        sum = inc_V;
    else if (strcmp(Str,dec) == 0)
        sum = dec_V;
    else if (strcmp(Str,jmp) == 0)
        sum = jmp_V;
    else if (strcmp(Str,bne) == 0)
        sum = bne_V;
    else if (strcmp(Str,red) == 0)
        sum = red_V;
    else if (strcmp(Str,prn) == 0)
        sum = prn_V;
    else if (strcmp(Str,jsr) == 0)
        sum = jsr_V;
    else if (strcmp(Str,rts) == 0)
        sum = rts_V;
    else if (strcmp(Str,stop) == 0)
        sum = stop_V;
    else
         sum = -1;

    arr[num] = sum;

    return sum;
}