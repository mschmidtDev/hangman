/**
 * A game of hangman
 * Authors: Johannes Busch, Merlin Schmidt
 */

#include <stdio.h>
#include <stdlib.h>
#include "end_game.h"
#include "input_check.h"
#include "timer.h"
#include "game_state.h"
#include "input.h"
#include "game_state.h"

int main()
{
    struct guess this_guess;

    this_guess = new_game();

    start_timer();

    int checker = 0;

    do {
        this_guess = input_letter(this_guess);

        print_result(this_guess);

        checker = check_win_or_lose(this_guess);
    }while(checker == 0);

    if (checker == 1) {
        printf("You lost! It took you %f seconds to come here.\n", cur_timer());
    } else if (checker == 2) {
        printf("You won! It took you %f seconds to come here.\n", cur_timer());
    }


    return 0;
}
