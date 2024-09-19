#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./string.h"
#include "./constant.h"

FILE * f = NULL;

char ** dico = NULL;
int dico_size = 0;

char * dico_get_random_word()
{
	srand(time(NULL));

	int index = rand() % dico_size;	

	return *(dico + index);
}


int dico_read(char *filename)
{

	// OPEN A FILE

	char * fullname = string_concatenate(DEFAULT_DICTIONARY_FOLDER, filename);
	f = fopen(fullname, "r");
	if(f == NULL)
	{
		fprintf(stderr, "Unable to open dictionary");
		return 1;
	}

	// MALLOC THE DICTIONARY

	dico = malloc(sizeof(char *) * DEFAULT_DICO_SIZE);
	if(dico == NULL)
	{
		fprintf(stderr, "Unable to malloc a dictionary");
		return 2;
	}

	// SET DICTIONARY VALUE
	

	char ** dico_ptr = dico;
	char * line = malloc(sizeof(char) * MAX_WORD_SIZE+1);
	if(line == NULL)
	{
		fprintf(stderr, "Unable to malloc a word");
		return 3;
	}


	while (NULL != fgets(line, MAX_WORD_SIZE, f))
	{
		*dico_ptr++ = line;

		/// REMOVE the last \n by a \0
		
		int word_length = string_get_length(line);
		line[word_length - 1] = '\0';


		///

		line = malloc(sizeof(char) * MAX_WORD_SIZE + 1);
		if(line == NULL)
		{
			fprintf(stderr, "Unable to malloc a word");
			return 3;
		}	
	}
	
	int size = (dico_ptr - dico);

	dico_size = size;

	if(size == 0)
	{
		free(line);
	}
	return 0;
}


