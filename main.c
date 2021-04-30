/**
 * A game of hangman
 * Authors: Johannes Busch, Merlin Schmidt
 */

#include <stdio.h>
#include <stdlib.h>
#include "end_game.h"
#include "timer.h"
#include "input.h"
#include "game_state.h"
#include "name_helper.h"

int main()
{
    struct guess this_guess;
    struct saved_usernames saved_usernames;

    saved_usernames = set_name(saved_usernames);

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
