#include "set.h"

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
	if(str1[i+j] != str2[i])
		return 0;
}

if (str1[i] == ' ' || str1[i] == '\n')
	return 1;
else
	return 0;
}

/* RETURN INT WITH THE NUMBERS OF SETS */
int check_sets (char str[])
{
	int i=0, count=0, set_p1,set_p2,set_p3;
	char *ret;
	char s[6][5] = {
		"SETA",
		"SETB",
		"SETC",
		"SETD",
		"SETE",
		"SETF",
	};

	for (i=0; i<6; i++){
	  ret = strstr(str,s[i]);
	  if(ret!=NULL){		
		count++;
		ret = strstr(str,s[i]);
		if (count == 1){
			set_p1=i;
			 /* AVOID 0 FOR Pset_cmd FUNC */
			pSet_cmd(set_p1+1);
	  	}
		if (count == 2){
			set_p2=i;
			printf("set 2 = %s\n", s[set_p2]);
	  	}
		if (count == 3){
			set_p3=i;
			printf("set 3 = %s\n", s[set_p3]);
	  	}
		
	  }
	}
		
return count;

}

int * read_check_nums (char str[])
{
	static int nums[SIZE];
	int total_n = 0;
	int n;
	int i;
	int index;

	/* RESET nums BEFORE ENTER NUMBERS */
	memset(nums,0,sizeof(int)*SIZE);

	while (1 == sscanf(str + total_n, "%*[^0123456789]%d%n", &i, &n))
	{
		if (i > SIZE)
		{
		num_err(i);
		nums[0]=EMPTY;
		break;
		}
		
    		total_n += n;
		nums[index] = i;
		index++;
	}

	nums[SIZE-1]=-1; 


return nums;
}

void cmd_err ()
{
printf(ERR "\nERROR: " RST "Undefined command name\n");
}

void set_err ()
{
printf(ERR "\nERROR: " RST "Undefined set name\n" );
}

void num_err (int e)
{
if (e > SIZE)
	printf(ERR "\nERROR: " RST "Invalid set member - value out of range\n" );

}

