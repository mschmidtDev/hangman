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

// Save highscores to highscores.csv
void save_highscore(struct guess this_guess, char *username, double time, int won)
{
    // declare fp as filepointer
    FILE * fp;

    // check if highscores.csv exists already
    if ((fp = fopen("highscores.csv", "r"))!=NULL) {
        // if it exists, continue with the rest
        fclose(fp);
    } else {
        // otherwise create it and write first line with column names
        fp = fopen("highscores.csv", "w");
        fprintf(fp, "Name, Word, Mistakes, Time, Won?, \n");
        fclose(fp);
    }

    // open highscores.csv in append mode
    (fp = fopen("highscores.csv", "a"));

    // print necessary data to next line in file
    fprintf(fp, "%s, %s, %d, %lf, %s, \n", username, this_guess.answer, this_guess.mistakes, time, ((won == 2) ? "won" : "lost"));
    fclose(fp);

    // tell user that highscore was saved
    printf("Saved to highscores.csv\n");
}
