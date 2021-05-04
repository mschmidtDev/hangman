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

    printf("Which gamemode do you want to play?\n Normal (1)\n Coop (2)\n Timed (3)\n Enter number: ");
    fflush(stdin);
    scanf("%i", &gamemode);

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
    int checker = 0;

    this_saved_usernames = set_name(this_saved_usernames);

    this_guess = new_game();

    printf("You're looking for a word this long: %s\n", this_guess.masked);

    start_timer();

    do {
        print_hangman(this_guess);

        this_guess = input_letter(this_guess);

        print_result(this_guess);

        checker = check_win_or_lose(this_guess);
    }while(checker == 0);

    printf("\n|--------------------------------|\n\n");

    if (checker == 1) {
        printf("%s: You lost! The correct word was: %s\nIt took you %f seconds to come here.\n", this_saved_usernames.name_1, this_guess.answer, cur_timer());
    } else if (checker == 2) {
        printf("%s: You won! It took you %f seconds to come here.\n", this_saved_usernames.name_1, cur_timer());
    }

    save_highscore(this_guess, this_saved_usernames.name_1, cur_timer(), checker);
}

// Co-op gamemode
void coop_game()
{
    struct guess this_guess;
    struct saved_usernames this_saved_usernames;
    int player = 1;
    int checker = 0;

    this_saved_usernames = set_names_coop(this_saved_usernames);

    this_guess = new_game();

    printf("You're looking for a word this long: %s\n", this_guess.masked);

    start_timer();

    do {
        print_hangman(this_guess);

        if (player % 2 == 0) {
            printf("%s (Player 2)!", this_saved_usernames.name_2);
        } else {
            printf("%s (Player 1)!", this_saved_usernames.name_1);
        }

        int mistake_check = this_guess.mistakes;

        this_guess = input_letter(this_guess);

        if (mistake_check < this_guess.mistakes) {
            player++;
        }

        print_result(this_guess);

        checker = check_win_or_lose(this_guess);
    }while(checker == 0);

    char winner[255];

    if (player % 2 == 0) {
        strcpy(winner, this_saved_usernames.name_2);
    } else {
        strcpy(winner, this_saved_usernames.name_1);
    }

    printf("\n|--------------------------------|\n\n");

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
    float time = 60;

    this_saved_usernames = set_name(this_saved_usernames);

    this_guess = new_game();

    printf("You're looking for a word this long: %s\n", this_guess.masked);

    start_timer();

    do {
        if (cur_timer() > time) {
            break;
        }

        print_hangman(this_guess);

        this_guess = input_letter(this_guess);

        print_result(this_guess);

        checker = check_win_or_lose(this_guess);
    }while(checker == 0);

    printf("\n|--------------------------------|\n\n");

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
