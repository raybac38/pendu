#include <stdlib.h>

char * dico_get_random_word()
{
	char * word = malloc(sizeof(char) * 5);
	word[0] = 'h';	
	word[1] = 'e';	
	word[2] = 'l';	
	word[3] = 'o';	
	word[4] = '\0';	
	return word;
}
