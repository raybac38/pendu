/*
 * The purpose of this script is to provide an API interacting with dictionaries
 */

/*
 * This function will try to detecte the folder ./dictionary
 * if detected, it will scan and repertory all available dictionary
 * else, it will try to create a ./dictionnary folder
 *
 *	@return : 0 if it succed
 *		  1 if an error occure
 */

int dico_init(void);


int dico_open(char * name);


/*
 * Return a random word from all active dictionnary
 * /!\ two same word in active dictionnary will have more luck to appear	
 */

char * dico_get_random_word();

