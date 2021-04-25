


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "game_state.h"
#include "input_check.h"

struct guess input_letter(struct guess this_guess)
{
    char new_letter = 'q';
    int correct = 0;

    do {
        printf("Enter your guess: ");
        fflush(stdin);
        scanf("%c", &new_letter);
        new_letter = tolower(new_letter);
    } while (!check_input(new_letter));

    printf("%c\n", new_letter);


    if (strchr(this_guess.masked, new_letter)) {
        printf("You already guessed this letter, try again.\n");
        return this_guess;
    }

    this_guess.guessed[(int) new_letter - 97] = new_letter;

    for (int i = 0; i < this_guess.answer_length; i++) {
        if (new_letter == this_guess.answer[i]) {
            this_guess.masked[i] = new_letter;
            correct = 1;
        }
    }
    this_guess.tries++;

    if (!correct) {
        this_guess.mistakes++;
    }

    return this_guess;
}
