#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./core.h"
#include "./dico_io.h"
#include "./constant.h"
#include "./terminal.h"
#include "./string.h"

void dictionary_manager(void);

int main(int argc, char ** argv)
{
	srand(time(NULL));
	fprintf(stdout, "Jeu du pendu\n\n");
	
	while(1)
	{
		char * answer = terminal_ask("\tPlay\n\tDictionary (unfinished)\n\tCredits\n\tQuit\n");
		if(string_is_equal(answer, "play"))
		{
			dico_read(DEFAULT_DICTIONARY_NAME);
			core_start_game();
		}
		else if(string_is_equal(answer, "dictionary"))
		{
			//Dictionary manager
			dictionary_manager();				
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

void add_word_protocol()
{
	char * dico_name = terminal_ask("dictionary name ?");
	int return_code = dico_read(dico_name);
	if(return_code != 0)
	{
		fprintf(stdout, "Unable to open this dictionary\n");
		if(dico_name != NULL)
		{
			free(dico_name);
		}
		return;
	}

	//Dictionary, have been read

	while(1)
	{
		fprintf(stdout, "Write and enter to add a word\n Enter nothing to go back\n");
		char * word = terminal_ask("What word do you want to add ?");
		if(string_get_length(word) < 1)
		{
			free(word);
			fprintf(stdout, "return to dictionary ... \n");
			break;
		}
		dico_add_word(word);
		fprintf(stdout, "Word added\n");
		free(word);

	}

	dico_write(dico_name);
	fprintf(stdout, "dico writed\n");
	free(dico_name);
}

void remove_word_protocol()
{
	char * dico_name = terminal_ask("dictionary name ?");
	int return_code = dico_read(dico_name);
	if(return_code != 0)
	{
		fprintf(stdout, "Unable to open this dictionary\n");
		if(dico_name != NULL)
		{
			free(dico_name);
		}
		return;
	}

	//Dictionary, have been read

	while(1)
	{
		fprintf(stdout, "Write and enter to remove if matching a word\n Enter nothing to go back\n");
		char * word = terminal_ask("What word do you want to remove ?");
		if(string_get_length(word) < 1)
		{
			free(word);
			fprintf(stdout, "return to dictionary ... \n");
			break;
		}
		dico_remove_word(word);
		fprintf(stdout, "Word removed");
		free(word);

	}
	dico_write(dico_name);
	free(dico_name);
}


void dictionary_manager()
{
	// list all dictionary
	// create a new dictionary
	// add word to a dictionary
	// remove word to a dictionary
	// back
	
	while (1)
	{
		fprintf(stdout, "\n\nDictionary Manager \n\n");
		fprintf(stdout, "\tlist   => list all available dictionary\n");
		fprintf(stdout, "\tcreate => create a new dictionary\n");
		fprintf(stdout, "\terase  => erase a dictionary\n");
		fprintf(stdout, "\tadd    => add a word to a dictionarry\n");
		fprintf(stdout, "\tremove => remove a word to a dictionary\n");
		fprintf(stdout, "\tback   => go back to the main menu\n");
		char * answer = terminal_ask("");
	
		if(string_is_equal(answer, "list"))
		{
			system("ls ./dictionary/");
		}
		if(string_is_equal(answer, "create"))
		{

			char * name = terminal_ask("dictionary name ? ");
			fprintf(stdout, "%s\n", name);
			int res = dico_create_empty(name);
			if(!res)
			{
				fprintf(stdout, "Sorry, Unable to create a new dictionary\nSee stderr for more info\n");
			}
			free(name);
		}
		if(string_is_equal(answer, "erase"))
		{
			char * name = terminal_ask("dictionary name ? ");
			dico_erase(name);
			free(name);
		}
		if(string_is_equal(answer, "add"))
		{
			add_word_protocol();
		}
		if(string_is_equal(answer, "remove"))
		{
			remove_word_protocol();
		}
		if(string_is_equal(answer, "back"))
		{
			return;
		}

	}

}
