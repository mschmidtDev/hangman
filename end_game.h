#ifndef END_GAME_H_INCLUDED
#define END_GAME_H_INCLUDED
#include "game_state.h"

// Function to check for win or lose
int check_win_or_lose (struct guess this_guess);

// Function to save the highscore
void save_highscore(struct guess this_guess, char *username, double time, int won);

#endif // END_GAME_H_INCLUDED
