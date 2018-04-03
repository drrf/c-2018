/*
	
	my_str.c -- suffix()
	
	Copyright © 2018 Ron .F.
	
	
	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

*/
#include <stdio.h>
# include <string.h>
#include "data.h"

int suffix(char str[SIZE], char ch){	
	int i, len, suf = 0;
	char copystr[SIZE];
	
	/* SAVE THE LENGTH OF THE STRING */
	len = strlen(str); 
	
	printf("\n");

	/* COUNT & DISPLAY THE SUFFIX IN THE STRING */
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (ch == str[i]){
			++suf;
			strncpy(copystr, str+i,len);
			printf("\t%d. %s", suf,copystr);
		}
	}

	printf("\n----------------------------------------\n");
	printf("\tThe num of suffix is: %d \n", suf);
	printf("----------------------------------------\n");
	
	return suf;
}

