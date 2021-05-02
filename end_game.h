#ifndef END_GAME_H_INCLUDED
#define END_GAME_H_INCLUDED
#include "game_state.h"

int check_win_or_lose (struct guess this_guess);

void save_highscore(struct guess this_guess, char *username, double time);

#endif // END_GAME_H_INCLUDED
