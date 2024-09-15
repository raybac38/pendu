
/*
 * This function initialise a word with the required size + '\0'
 * set all char to value (prevent \0 to be in)
 */
char * string_init_word(int size, char value);

/*
 * get the legth of the string
 */
int string_get_length(char * string);

/*
 * Compare two string
 * @return 1 if equal, 0 if inequal
 */

int string_is_equal(char * string1, char * string2);

/*
 * Return the number of chararcter on a stirng
 */

int string_count_character_occurences(char * string, char character);

/*
 * This function set $(character) in string2 if $(character) is equal to string1 
 */

void string_reveal_occurences(char * string1, char character, char * string2);

