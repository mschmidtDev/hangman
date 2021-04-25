#include <stdio.h>
#include <string.h>
#include "game_state.h"

// start new game
struct guess new_game(void)
{
    struct guess this_guess;

    this_guess.tries = 0;
    this_guess.mistakes = 0;

    fflush(stdin);
    scanf("%s", this_guess.answer);
    for(int i = 0; this_guess.answer[i]; i++){
        this_guess.answer[i] = tolower(this_guess.answer[i]);
    }
    this_guess.answer_length = strlen(this_guess.answer);

    for (int i = 0; i < this_guess.answer_length; i++) {
        this_guess.masked[i] = '_';
    }

    for (int i = 0; i < 26; i++) {
        this_guess.guessed[i] = '_';
    }
    this_guess.guessed[26] = 0;

    return this_guess;
};

// print word with the guessed letters
void print_result(struct guess this_guess)
{
    for (int i = 0; i < this_guess.answer_length; i++) {
        printf("%c", this_guess.masked[i]);
    }
    printf("\nYou were %d times wrong.\n", this_guess.mistakes);


}
