#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "end_game.h"
#include "timer.h"
#include "input.h"
#include "game_state.h"
#include "name_helper.h"
#include "gamemode.h"

// Function to select the gamemode the user wants to play
int select_gamemode()
{
    int gamemode = 0;

    // Select the gamemode you want to play
    printf("Which gamemode do you want to play?\n Normal (1)\n Coop (2)\n Timed (3)\n Enter number: ");
    fflush(stdin);
    scanf("%i", &gamemode);

    // Check for valid inputs
    while (gamemode != 1 && gamemode != 2 && gamemode != 3) {
        printf("\nNot a valid gamemode, please try again: ");
        fflush(stdin);
        scanf("%i", &gamemode);
    }

    return gamemode;
}

// Gamemode for a normal game
void normal_game()
{
    struct guess this_guess;
    struct saved_usernames this_saved_usernames;
    // Variable to save win/lose - result
    int checker = 0;

    // Get usernames
    this_saved_usernames = set_name(this_saved_usernames);

    // Start the game
    this_guess = new_game();

    // Print word-length
    printf("You're looking for a word this long: %s\n", this_guess.masked);

    // Start the timer
    start_timer();

    // Game-loop
    do {
        // Print the hangman
        print_hangman(this_guess);

        // Letter input from user
        this_guess = input_letter(this_guess);

        // Print the results
        print_result(this_guess);

        // Check if game should go on or was lost/won
        checker = check_win_or_lose(this_guess);
    }while(checker == 0);

    // For visibility
    printf("\n|--------------------------------|\n\n");

    // Check if won or lost, print accordingly
    if (checker == 1) {
        printf("%s: You lost! The correct word was: %s\nIt took you %f seconds to come here.\n", this_saved_usernames.name_1, this_guess.answer, cur_timer());
    } else if (checker == 2) {
        printf("%s: You won! It took you %f seconds to come here.\n", this_saved_usernames.name_1, cur_timer());
    }

    // Save game in highscore list
    save_highscore(this_guess, this_saved_usernames.name_1, cur_timer(), checker);
}

// Co-op gamemode
void coop_game()
{
    struct guess this_guess;
    struct saved_usernames this_saved_usernames;
    // Variable to check which players turn it is
    int player = 1;
    // Variable to check if game is won or lost
    int checker = 0;

    // Set names (Name 1 is used for player1, name 2 for player2)
    this_saved_usernames = set_names_coop(this_saved_usernames);

    // Start the game
    this_guess = new_game();

    // Print the word-length
    printf("You're looking for a word this long: %s\n", this_guess.masked);

    // Start the timer
    start_timer();

    // Game-loop
    do {
        // Print the hangman
        print_hangman(this_guess);

        // Output for Player 1 or 2
        if (player % 2 == 0) {
            printf("%s (Player 2)!", this_saved_usernames.name_2);
        } else {
            printf("%s (Player 1)!", this_saved_usernames.name_1);
        }

        // Safe current mistakes
        int mistake_check = this_guess.mistakes;

        // Get Player-input
        this_guess = input_letter(this_guess);

        // Check if previous mistakes are less than current, if yes, next player
        if (mistake_check < this_guess.mistakes) {
            player++;
        }

        // Print round-result
        print_result(this_guess);

        // Check for win/lose/ongoing
        checker = check_win_or_lose(this_guess);
    }while(checker == 0);

    // Variable to save winners name
    char winner[255];

    // Save winner
    if (player % 2 == 0) {
        strcpy(winner, this_saved_usernames.name_2);
    } else {
        strcpy(winner, this_saved_usernames.name_1);
    }

    printf("\n|--------------------------------|\n\n");

    // Print Win/lose
    if (checker == 1) {
        printf("%s: You lost the game for both of you! The correct word was: %s\nIt took you %f seconds to come here.\n", winner, this_guess.answer, cur_timer());
    } else if (checker == 2) {
        printf("%s: You won the game for both of you! It took you %f seconds to come here.\n", winner, cur_timer());
    }
}

// Gamemode for a timed game
void timed_game()
{
    struct guess this_guess;
    struct saved_usernames this_saved_usernames;
    int checker = 0;
    // Variable for the timer, lose if exceeded
    float time = 60;

    this_saved_usernames = set_name(this_saved_usernames);

    this_guess = new_game();

    printf("You're looking for a word this long: %s\n", this_guess.masked);

    start_timer();

    do {
        // Check if lost by time
        if (cur_timer() > time) {
            break;
        }

        print_hangman(this_guess);

        this_guess = input_letter(this_guess);

        print_result(this_guess);

        checker = check_win_or_lose(this_guess);
    }while(checker == 0);

    printf("\n|--------------------------------|\n\n");

    // Automatic lose if time exceeds 60 seconds
    if (cur_timer() > time) {
        printf("You ran out of time! We'll get 'em next time!");

        return;
    }

    if (checker == 1) {
        printf("%s: You lost! The correct word was: %s\nIt took you %f seconds to come here.\n", this_saved_usernames.name_1, this_guess.answer, cur_timer());
    } else if (checker == 2) {
        printf("%s: You won! It took you %f seconds to come here.\n", this_saved_usernames.name_1, cur_timer());
    }

    save_highscore(this_guess, this_saved_usernames.name_1, cur_timer(), checker);
}
