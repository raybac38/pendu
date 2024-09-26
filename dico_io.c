#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#include "./string.h"
#include "./constant.h"

FILE * f = NULL;

char ** dico = NULL;
int dico_size = 0;


char * dico_get_random_word()
{
	int index = rand() % dico_size;	
	return *(dico + index);
}

void dico_null_pointer()
{
	int starting_index = dico_size;
	for (int index = starting_index; index < DEFAULT_DICO_SIZE; index ++)
	{
		dico[index] = NULL;
	}
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

	dico_null_pointer();
	return 0;
}

int dico_create_empty(char * name)
{
	FILE * f = NULL;

	char * fullname = string_concatenate(DEFAULT_DICTIONARY_FOLDER, name);
	fprintf(stdout, "%s\n", fullname);
	f = fopen(fullname, "w+");
	if(f == NULL)
	{
		return 2;
	}
	fclose(f);

	fprintf(stdout, "new dictionary succesfully created\n");

	free(fullname);
	return 0;

}

void dico_erase(char * name)
{
	char * fullname = string_concatenate(DEFAULT_DICTIONARY_FOLDER, name);
	char * cmd = string_concatenate("rm ", fullname);
	system(cmd);
	fprintf(stdout, "Dictionary erased\n");
	free(fullname);
	free(cmd);
	return;
}

//FUNCTION WILL CREATE A COPY
void dico_add_word(char * word)
{
	if(dico_size == DEFAULT_DICO_SIZE)
	{
		return;
	}
	char ** ptr = dico;
	while(*ptr++) {}

	char * copy = string_copy(word);

	*ptr = copy;

	dico_size ++;
	return;
}

void dico_remove_word(char * word)
{
	char ** ptr = dico;
	int countdown = DEFAULT_DICO_SIZE;

	while(!string_is_equal(*ptr, word) && countdown)
	{
		ptr ++;
		countdown--;
	}
	if(!countdown)
	{
		fprintf(stdout, "Cannot find your word\n");
		return;
	}
	printf("%s\n", *ptr);
	free(*ptr);
	dico_size--;
	*ptr = NULL;
}

int dico_write(char * filename)
{
	if(dico == NULL)
	{
		fprintf(stderr, "Unable to find dico raw data\n");
		return 1;
	}

	char * fullname = string_concatenate(DEFAULT_DICTIONARY_FOLDER, filename);
	f = fopen(fullname, "w");
	if(f == NULL)
	{
		fprintf(stderr, "Unable to open dictionary");
		return 1;
	}

	char ** ptr = dico;

	while(dico_size != 0)
	{
		if(*ptr == NULL)
		{
			fprintf(f, "%s\n", *ptr);
			dico_size--;
		}
		ptr++;
	}
	free(fullname);
	fclose(f);
}





