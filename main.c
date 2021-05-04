/**
 * A game of hangman
 * Authors: Johannes Busch, Merlin Schmidt
 * Please read the readme.md before using this
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "gamemode.h"

int main()
{
    int gamemode;

    gamemode = select_gamemode();

    if (gamemode == 1) {
        normal_game();
    } else if (gamemode == 2) {
        coop_game();
    } else if (gamemode == 3) {
        timed_game();
    } else {
        printf("You shouldn't be here! :think:");
    }

    sleep(10000);

    return 0;
}
