#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "game_state.h"

// Check if game was lost or won in last round ( 0 if nothing, 1 if lost, 2 if won
int check_win_or_lose(struct guess this_guess)
{
    if (this_guess.mistakes > 9) {
        return 1;
    }


    if (!strcmp(this_guess.masked, this_guess.answer)) {
        return 2;
    } else {
        return 0;
    }
}

void save_highscore(struct guess this_guess, char *username, double time)
{
    FILE * fp;

    fp = fopen("highscores.csv", "a");

    fprintf(fp, "%s, %s, %d, %lf, \n", username, this_guess.answer, this_guess.tries, time);
    printf("Saved to highscores.\n");

    fclose(fp);
}
