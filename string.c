#include <stdio.h>
#include <stdlib.h>

int string_get_length(char * string)
{
	int size = 0;
	while(*string++)
	{
	size ++;
	}
	return size;	
}

char * string_init_word(int size, char value)
{
	char * str = malloc(sizeof(char) * (size + 1));
	if(str == NULL)
	{
		fprintf(stderr, "Unable to malloc a new word");
	}
	char * ptr = str;

	while(size != 0)
	{
		*ptr++ = value;
		size--;
	}
	*ptr = 0;
	return str;

}

