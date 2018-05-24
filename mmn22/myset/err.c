/*
 *          File: err.c
 *        Author: Ron F. <>
 * Last Modified: May 23, 2018
 *         Topic: ???
 * ----------------------------------------------------------------
 */

#include "set.h"

void cmd_err ()
{
printf(ERR "\nERROR: " RST "Undefined command name\n");
}

void cmd_comma_err ()
{
printf(ERR "\nERROR: " RST "Illegal comma\n");
}

void set_err ()
{
printf(ERR "\nERROR: " RST "Undefined set name\n" );
}

void set_extra_err ()
{
printf(ERR "\nERROR: " RST "Exraneous text after end of command\n" );
}

void set_err_miss ()
{
printf(ERR "\nERROR: " RST "Missing parameter\n" );
}

void num_err (int e)
{
if (e == BLOCK)
	printf(ERR "\nERROR: " RST "List of set members is not terminated correctly\n" );

if (e > SIZE)
	printf(ERR "\nERROR: " RST "Invalid set member - value out of range\n" );

}

void num_end_err (int e)
{
if (e == END)
	printf(ERR "\nERROR: " RST "List of set members is not terminated correctly\n" );
}


void stop_by_eof ()
{
	printf(ERR "\nERROR: " RST "THIS IS END OF FILE (EOF)\n" );
	stop();
}

void comma_err (int c)
{
	if (c > 1)
	printf(ERR "\nERROR: " RST "Multiple consecutive commas\n" );

	if (c == 0)
	printf(ERR "\nERROR: " RST "Missing comma\n" );
}
