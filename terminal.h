/*
 *	The purpose of this script is to provide easy-to-use functions for communication with the user via terminal
 */

#ifndef TERMINAL_H
#define TERMINAL_H

/*
 * Print the argument in the terminal
 * return to the line after
 */
void terminal_write(char * string);

/*
 * Request an awnser from the user
 */
char * terminal_ask(char * string);

#endif

