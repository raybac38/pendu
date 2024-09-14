#include <stdio.h>

#include "./dico_io.h"
#include "./string.h"
#include "./constant.h"
#include "./terminal.h"

/*
 * This function computes the number of turns that is needed to play
 * short word require more letter to be feasible,
 * long word need fewer turn because it is too easy
 *
 * This function is capped
 */

int get_turn_number(int word_score)
{
	//difficulty will be added, but now it is hardcoded
	float a = 0.5f;
	float b = 6;
	int max = 15;
	int res = (int) (a * word_score + b);
	if( res > max)
	{
		res = max;
	}
	return res;
}

void core_start_game(void)
{
	
	//hidden_word is the word that need to be find
	char * hidden_word = dico_get_random_word();

	int hidden_score = string_get_length(hidden_word);
	int turn = get_turn_number(hidden_score);
	int score = 0;

	char * showed_word = string_init_word(hidden_score, DEFAULT_HIDER_CHAR);

	while(hidden_score != score && turn)
	{
		//gameplay loop
		


		terminal_write("Your word is :");
		terminal_write(showed_word);
		fprintf(stdout, "you have %i try left\n", turn);

		char * answer = terminal_ask("tel me a lettre of try a word !");

		//if letter 
		//	need to detecte if the letter is in the word
		//	YES => change all "-" by the letter
		//	NO => store the wrong letter
		//
		//if word 
		//	YES => win
		//	NO => nothing
		//
		//after :
		//	pass a turn
			
		turn--;
	
	}



	


}
