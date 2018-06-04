/*
 *          File: err.c
 *        Author: Ron F. <>
 * Last Modified: June 04, 2018
 *         Topic: Read commands from input & save and use data
 * ----------------------------------------------------------------
 */

#include "set.h"

/* COLOR */
#define ERR     "\x1b[31m"  /* RED COLOR OF ERR */
#define RST   "\x1b[0m"		/* RESET TO ORG COLOR */


/* UNDEFINED COMMAND NAME */
void cmd_err ()
{
printf(ERR "\nERROR: " RST "Undefined command name\n");
}

/* ILLEGAL COMMA */
void cmd_comma_err ()
{
printf(ERR "\nERROR: " RST "Illegal comma\n");
}

/* UNDEFINED SET NAME */
void set_err ()
{
printf(ERR "\nERROR: " RST "Undefined set name\n" );
}

/* EXTANEOUS TEXT */
void set_extra_err ()
{
printf(ERR "\nERROR: " RST "Exraneous text after end of command\n" );
}

/* MISSING PARAMETER */
void set_err_miss ()
{
printf(ERR "\nERROR: " RST "Missing parameter\n" );
}

/* NOT TERMINATED CORRECTLY */
void num_end_err ()
{
	printf(ERR "\nERROR: " RST "List of set members is not terminated correctly\n" );
}

/* VALUE OUT OF RANGE */
void num_err (int e)
{
if (e == BLOCK)
	printf(ERR "\nERROR: " RST "List of set members is not terminated correctly\n" );

if (e > SIZE)
	printf(ERR "\nERROR: " RST "Invalid set member - value out of range\n" );

}

/* NOT AN INTEGER */
void not_int ()
{
	printf(ERR "\nERROR: " RST "Invalid set member - not an integer\n" );
}

/* ERROR WITH COMMA */
void comma_err (int c)
{
	if (c > 1)
	printf(ERR "\nERROR: " RST "Multiple consecutive commas\n" );

	if (c <= 0)
	printf(ERR "\nERROR: " RST "Missing comma\n" );
}

/* THE END OF FILE */
void stop_by_eof ()
{
	printf(ERR "\nWARNING: " RST "THIS IS END OF FILE (EOF)\n" );
	stop();
}
