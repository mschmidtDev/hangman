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
    struct saved_usernames this_saved_usernames;

    this_saved_usernames = set_name(this_saved_usernames);

    this_guess = new_game();

    printf("You're looking for a word this long: %s\n", this_guess.masked);

    start_timer();

    int checker = 0;

    do {
        print_hangman(this_guess);

        this_guess = input_letter(this_guess);

        print_result(this_guess);

        //printf("%s\n%s\n", this_guess.masked, this_guess.answer);

        checker = check_win_or_lose(this_guess);
    }while(checker == 0);

    if (checker == 1) {
        printf("%s: You lost! The correct word was: %s\nIt took you %f seconds to come here.\n", this_saved_usernames.name_1, this_guess.answer, cur_timer());
    } else if (checker == 2) {
        printf("%s: You won! It took you %f seconds to come here.\n", this_saved_usernames.name_1, cur_timer());
    }
    save_highscore(this_guess, this_saved_usernames.name_1, cur_timer(), checker);


    return 0;
}
