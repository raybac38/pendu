#include <stdio.h>
#include <stdlib.h>

#include "./constant.h"

char * terminal_ask(char * string)
{
	fprintf(stdout, "%s\n>", string);
	char * answer = malloc(sizeof(char) * (MAX_WORD_SIZE + 1));

	if(answer == NULL)
	{
		fprintf(stderr, "Unable to malloc memory");
		exit(EXIT_FAILURE);
	}

	if(NULL == fgets(answer, MAX_WORD_SIZE + 1, stdin))
	{
		fprintf(stderr, "Unable to read from stdin");
		free(answer);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%s\n", answer);
	return answer;
}

