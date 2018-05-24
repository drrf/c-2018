/*
 *          File: set.h
 *        Author: Ron F. <>
 * Last Modified: May 23, 2018
 *         Topic: ???
 * ----------------------------------------------------------------
 */

#include "set.h"

/* REMOVE WHITE SPACE */
char * remove_2_white (char str1[])
{
int i=0,j=0,len=strlen(str1);
char * str2 = malloc(sizeof(char));

while(len--)
{
if (!isspace(str1[i])) {
		str2[j++] = str1[i];
}
else if (str2[j-1]!=' ') {
	str2[j++] = ' ';
} else
	;

i++;
}
str2[--j]='\0';
/*printf("str2 = %s", str2);*/
return str2;
}

/* SKIP ON WHITE SPACE */
int space (char str [])
{
int i = 0;
while (isspace(str[i++]))
	;

return i-1;
}

/* CHECK THE CMD IS VALID */
int check_line(char str1 [], char str2 [])
{
int  i = 0, j = space(str1);
int len = strlen(str2);

for (i=0;i<len;i++){
	if(str1[i+j] != str2[i]) {
		cmd_err();
		return 0;
	}
}

/* COMMA ERR ON CMD */
if (str1[i] == ',' || str1[i+1] == ','){
	cmd_comma_err();
	return 0;
}

/* IF TRUE RETURN INDEX TO END OF CMD, OR RETURN 0 */
if (str1[i] == ' ' || str1[i] == '\0' || str1[i] == '\n'){
		return i;
	} else {
		cmd_err();
		return 0;
	}

}

/* RETURN INT WITH THE NUMBERS OF SETS */
int check_sets (char str[], int t)
{
	/* printf("STR = %s, C = %c\n", str+i, str[i]); */
	/* REMOVE WHITE BLANK */
	int i=space(str),j=0,save_t=t;
	int count=0,comma=0,len,set_p,ind_p=0;
	char cpy[3]= {"SET"};
	len = strlen(str);

	/* FIX T WITH save_t */
	if (save_t == READ_SET)
		t=1;

	/* QUICK CHECK FOR "S" IF NOT EXIT */
	if (str[i]!='S') {
		set_err();
		return 0;
	}

   while (i<len && t >= 1){
	/* START CHECK */
	while(str[i++] == cpy[j++])
		;
	i--;j--;
	/* CHECK str[i] IS LAST LATTER OF SET NAME */
	if (j!=3 || str[i] < A_SET || str[i] > Z_SET){
		set_err();
		return 0;
	} else {
	   count++;
	   set_p = str[i]-A_TO_NUM;
	   pSet_cmd(set_p,ind_p++);
	   j = 0; /* RESET J TO NEXT TIME */
	}
	
	if (t > 1){
		i++;

		/* EXIT ERR COMMA */
		comma = check_comma(str+i);
		if (comma != 1)
			return 0;

		if (comma == 1){
			i++;
		}
		if (str[i] == ','){
			i++;
		}
		if (str[i] == ' '){
			i++;
		}
	} 

	if (t == 1){
		if (save_t == READ_SET){
			i++;
			comma = check_comma(str+i);
			if (comma != 1){
				return 0;
			} else {
				readset(str+i);
				return count;
			}
		}
		i++;
		if (str[i] != 0 ){
			set_extra_err();
			return 0;
		}
	} t--;
   } /* END OF WHILE */

	if (save_t == 3 && save_t!=count)
		set_err_miss();
		
return count;

}

int check_comma (char str[])
{
	int i = 0, comma = 0;
	while (str+i){
		if (str[i] == ','){
			comma++;
			i++;
		}
		else if (str[i] == ' '){
			i++;
		} else {
			break;
		}
	} /* END OF WHILE */

	if (comma > 1)
		comma_err(comma);
	else if (comma == 0)
		comma_err(comma);
	return comma;
}

int * read_check_nums (char str[])
{
	static int nums[SIZE+1];
	int i=0, n=0, total_n = 0, comma = 0, check;
	int len = strlen(str);
	int end = len;

	/* RESET nums BEFORE ENTER NUMBERS */
	memset(nums,0,sizeof(int)*SIZE);

	while (isspace(str[--end]))
		;

	/* FIRST CHECK: END -1 */
	if (str[end]!='1' || str[--end]!='-'){
		num_end_err (END);
		nums[0]=BLOCK;
		return nums;
	}

	while (len--)
	{
		if (i < end){
			if (str[i] == ',')
				comma++;

			if (isdigit(str[i])){
				total_n++;
				n=atoi(str+i);
				nums[n] = n;
				if (n>99)
					i = i+1;
				if (n>10)
					i++;
			}

			if (str[i] == '-' || n >= SIZE){
				num_err (SIZE + 1);
				nums[0]=BLOCK;
				return nums;
			}
	
			if (!isdigit(str[i]) && str[i] != ',' && str [i] != ' '){
					not_int ();
					nums[0]=BLOCK;
					return nums;
			}
			i++;
		}
	} /* END OF WHILE */

	check = comma-total_n;
	if (check > 1 || check <= 0){
		comma_err(check);
		nums[0]=BLOCK;
		return nums;
	}

	/* END OF ARRAY */
	nums[SIZE]=-1; 
return nums;
}
