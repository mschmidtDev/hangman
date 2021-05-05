/**
 * A game of hangman
 * Authors: Johannes Busch, Merlin Schmidt
 * Please read the readme.md before using this
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gamemode.h"

int main()
{
    int gamemode;

    // Select the gamemode
    gamemode = select_gamemode();

    // Start that gamemode
    if (gamemode == 1) {
        normal_game();
    } else if (gamemode == 2) {
        coop_game();
    } else if (gamemode == 3) {
        timed_game();
    } else {
        printf("You shouldn't be here! :think:");
    }

    // Sleep 10 seconds, gives user time to read results
    sleep(10);

    return 0;
}
