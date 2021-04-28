#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "game_state.h"
#include "input_check.h"

// guess one letter
struct guess input_letter(struct guess this_guess)
{
    // prepare variables
    char new_letter = 0;
    int correct = 0;

    // user enters a char until a valid letter is given
    do {
        printf("Enter your guess: ");
        fflush(stdin);
        scanf("%c", &new_letter);
        // make guess lowercase
        new_letter = tolower(new_letter);
    } while (!check_input(new_letter));

    // tell user if letter was guessed already
    if (strchr(this_guess.masked, new_letter)) {
        printf("You already guessed this letter, try again.\n");
        return this_guess;
    }

    // add guessed letter to array of guessed letters at corresponding position
    this_guess.guessed[(int) new_letter - 97] = new_letter;

    // iterate over answer and check if letter is correct
    for (int i = 0; i < this_guess.answer_length; i++) {
        if (new_letter == this_guess.answer[i]) {
            // if letter is correct, replace the '_' in masked with that letter
            this_guess.masked[i] = new_letter;
            // save letter as correct guess
            correct = 1;
        }
    }

    // increment tries
    this_guess.tries++;

    // if guess was wrong, increment mistakes
    if (!correct) {
        this_guess.mistakes++;
    }

    // return guess struct
    return this_guess;
}
