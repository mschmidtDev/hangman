#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "game_state.h"

// Check if game was lost or won in last round
int check_win_or_lose(struct guess this_guess)
{
    if (this_guess.mistakes > 10) {
        return 1;
    }


    if (strcmp(this_guess.masked, this_guess.answer)) {
        return 1;
    } else {
        return 0;
    }
}
