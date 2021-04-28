#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "game_state.h"
#include "timer.h"

// start new game
struct guess new_game(void)
{
    // initialize guess struct
    struct guess this_guess;

    // set starting values
    this_guess.tries = 0;
    this_guess.mistakes = 0;

    // let user input guess (for now)
    fflush(stdin);
    scanf("%s", this_guess.answer);
    // make guess lowercase
    for(int i = 0; this_guess.answer[i]; i++){
        this_guess.answer[i] = tolower(this_guess.answer[i]);
    }
    // save guess length
    this_guess.answer_length = strlen(this_guess.answer);

    // prepare masked string for showing the progress
    for (int i = 0; i < this_guess.answer_length; i++) {
        this_guess.masked[i] = '_';
    }

    // create array for showing guessed letters
    for (int i = 0; i < 26; i++) {
        this_guess.guessed[i] = '_';
    }
    this_guess.guessed[26] = 0;

    // return guess struct
    return this_guess;
};

// print word with the guessed letters
void print_result(struct guess this_guess)
{
    // print progress of guessed word
    for (int i = 0; i < this_guess.answer_length; i++) {
        printf("%c", this_guess.masked[i]);
    }

    printf("You guessed these letters so far:\n%s\n", this_guess.guessed);

    // tell user time used so far
    printf("You used %f seconds so far.\n", cur_timer());

    // tell user amount of tries and mistakes
    printf("You guessed a total of %d times.\n", this_guess.tries);
    printf("You were wrong %d times.\n", this_guess.mistakes);
}
