#include <stdio.h>
#include <stdlib.h>

#include "./constante.h"

FILE * f = NULL;

typdef struct{
	int length;
	char ** words; 
} dico_data;



char * dico_get_random_word()
{
	char * word = malloc(sizeof(char) * 6);
	word[0] = 'h';	
	word[1] = 'e';	
	word[2] = 'l';	
	word[3] = 'l';	
	word[4] = 'o';	
	word[5] = '\0';	
	return word;
}

int dico_open(char * name)
{
	char * fullname = string_concatenate(DEFAULT_DICTIONARY_FOLDER, name);
	f = fopen(fullname, "w");
	if(f == NULL)
	{
		fprintf(stderr, "Unable to open dictionary");
		return 1;
	}
	return 0;
}


