#include "end_game.h"

// Check if game was won (returns 1 on win, 0 if not won yet)
int check_won(int[] result)
{
    int checker = 1;
    int array_length = sizeof(result)/sizeof(result[0]);

    for (int i = 0; i < array_length; i++) {
        if (result[i] != 1) {
            checker = 0;
        }
    }

    return checker;
}

// Check if game was lost (returns 1 if game is lost, 0 when ongoing
int check_lost(int used, int chances)
{
    if (used >= chances) {
        return 1;
    }
}

