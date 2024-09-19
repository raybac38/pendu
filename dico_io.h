#ifndef DICO_IO_H
#define DICO_IO_H

/*
 * The purpose of this script is to provide an API interacting with dictionaries
 */

typedef struct s_dico
{
	int size;
	char ** data;
} s_dico;

/*
 * This function will try to detecte the folder ./dictionary
 * if detected, it will scan and repertory all available dictionary
 * else, it will try to create a ./dictionnary folder
 *
 *	@return : 0 if it succed
 *		  1 if an error occure
 */

int dico_init(void);

/*
 * Try to open a dictionary
 * return 0 if dictionary is open
 * return !0 if failed to open dictionary
 * 	(give a error code)
 */
int dico_read(char * filename);


/*
 * Return a random word from all active dictionnary
 * /!\ two same word in active dictionnary will have more luck to appear	
 */

char * dico_get_random_word();


#endif
