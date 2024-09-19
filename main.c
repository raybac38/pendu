#include <stdio.h>
#include <stdlib.h>

#include "./core.h"
#include "./dico_io.h"
#include "./constant.h"
#include "./terminal.h"
#include "./string.h"

int main(int argc, char ** argv)
{
	fprintf(stdout, "Jeu du pendu\n\n");
	
	while(1)
	{
		char * answer = terminal_ask("\tPlay\n\tDictionary\n\tCredits\n\tQuit\n");
		if(string_is_equal(answer, "play"))
		{
			dico_read(DEFAULT_DICTIONARY_NAME);
			core_start_game();
		}
		else if(string_is_equal(answer, "dictionary"))
		{
			//Dictionary manager				
		}
		else if(string_is_equal(answer, "credits"))
		{
			fprintf(stdout, "\n\n\n\tCredits : \n\n");
			fprintf(stdout, "Main coder : my keyboard, my trackpad and too much coffee\n");
			fprintf(stdout, "Tester : My cat, who walk on my keyboard\n");
			fprintf(stdout, "Artistic direction : my procrastination\n");
			fprintf(stdout, "Linguistic support : \n");
			fprintf(stdout, "Moral support : playlist n° 666\n");
			fprintf(stdout, "Quality check : segmentation fault (oops)\n");
			fprintf(stdout, "Thank you for playing this game, probably harder to play than to code :D\n\n");
			

		}else if(string_is_equal(answer, "quit"))
		{
			fprintf(stdout, "Quitting . . . \n");
			exit(EXIT_SUCCESS);
		}
	}
}

