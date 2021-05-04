#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "game_state.h"
#include "timer.h"
#include "name_helper.h"

// start new game
struct guess new_game(void)
{
    // initialize guess struct
    struct guess this_guess;

    // set starting values
    this_guess.tries = 0;
    this_guess.mistakes = 0;

    // read words file and choose one random word from it
    FILE * words;

    // if file can't be opened, let the user input the guess
    if ((words = fopen("encrypted.txt", "r")) == NULL) {
        printf("Error! Couldn't open word list. Enter your own guess instead: ");
        fflush(stdin);
        scanf("%s", this_guess.answer);
        // make answer lowercase
        for(int i = 0; this_guess.answer[i]; i++){
            this_guess.answer[i] = tolower(this_guess.answer[i]);
        }
    } else {
        // prepare randomly choosing a word
        srand(time(0));
        char line[256];
        int line_number = 0;
        int chosen_line = (rand() % 832);
        // iterate over file
        while (fgets(line, sizeof(line), words)) {
            // copy chosen line into answer
            if (chosen_line == line_number) {
                for (int i = 0; line[i] != '\n'; i++) {
                    if (line[i] <= 'm') {
                        line[i] = (char)(line[i] + 13);
                    } else {
                        line[i] = (char)(line[i] - 13);
                    }
                }
                strcpy(this_guess.answer, line);
                // remove '\n' in answer
                this_guess.answer[strcspn(this_guess.answer, "\n")] = '\0';
                break;
            } else {
                // keep iterating
                line_number++;
            }
        }
        printf("\n|--------------------------------|\n\n");
        printf("A word has been chosen.\n");
    }


    // save guess length
    this_guess.answer_length = strlen(this_guess.answer);
    this_guess.answer[this_guess.answer_length] = '\0';

    // prepare masked string for showing the progress
    for (int i = 0; i < this_guess.answer_length; i++) {
        this_guess.masked[i] = '_';
    }

    // Append \0 to end string
    this_guess.masked[this_guess.answer_length] = '\0';

    // create array for showing guessed letters
    for (int i = 0; i < 26; i++) {
        this_guess.guessed[i] = ' ';
    }
    this_guess.guessed[26] = 0;

    // return guess struct
    return this_guess;
};

// print word with the guessed letters
void print_result(struct guess this_guess)
{
    printf("\n|--------------------------------|\n\n");
    // print progress of guessed word
    for (int i = 0; i < this_guess.answer_length; i++) {
        printf("%c", this_guess.masked[i]);
    }

    printf("\nYou guessed these letters so far:\n%s\n", this_guess.guessed);

    // tell user time used so far
    printf("You used %f seconds so far.\n", cur_timer());

    // tell user amount of tries and mistakes
    printf("You guessed a total of %d times.\n", this_guess.tries);
}

void print_hangman(struct guess this_guess)
{
    char hangman[10] = "         ";

    switch(this_guess.mistakes) {
        case 9: hangman[8] = '\\';
        case 8: hangman[7] = '/';
        case 7: hangman[6] = '|';
        case 6: hangman[5] = '\\';
        case 5: hangman[4] = '|';
        case 4: hangman[3] = '/';
        case 3: hangman[2] = 'O';
        case 2: hangman[1] = '|';
        case 1: hangman[0] = '|';
    }

    printf("\t__________\n"
           "\t|       %c \n"
           "\t|       %c \n"
           "\t|       %c \n"
           "\t|      %c%c%c\n"
           "\t|       %c \n"
           "\t|      %c %c\n"
           "\t|         \n"
           "\t==========\n",
           hangman[0], hangman[1], hangman[2], hangman[3],
           hangman[4], hangman[5], hangman[6], hangman[7],
           hangman[8]
           );
}
