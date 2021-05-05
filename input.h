#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include "game_state.h"

// Function to automate the input of guesses
struct guess input_letter(struct guess this_guess);

// Function to check the inputs for validity
int check_input(char input);

#endif // INPUT_H_INCLUDED
