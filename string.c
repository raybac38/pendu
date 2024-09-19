
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

int string_is_equal(char * string1, char * string2)
{
	while(*string1 == *string2 && *string1 != 0 && *string2 != 0)
	{
		string1++; string2++;
	}
	return *string1 == *string2;
}


int string_count_character_occurences(char * string, char character)
{
	int count = 0;
	while(*string != 0)
	{
		if(*string++ == character)
		{
			count ++;
		}
	}
	return count;
}



void string_reveal_occurences(char * string1, char character, char * string2)
{
	while(*string1)
	{
		if(*string1 == character)
		{
			*string2 = *string1;
		}
		string1++; string2++;
	}
	return;
}

char * string_concatenate(char * string1, char * string2)
{
	int len = string_get_length(string1) + string_get_length(string2);
	char * str = malloc(sizeof(char) * (len + 1 ));
	char * ptr = str;

	while(*string1)
	{
		*ptr++ = *string1++;
	}
	while(*string2)
	{
		*ptr++ = *string2++;
	}
	*ptr = '\0';
	return str;
}

