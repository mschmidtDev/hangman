#ifndef GAME_STATE_H_INCLUDED
#define GAME_STATE_H_INCLUDED

// create guess struct with all necessary data for one guess
struct guess
{
    int answer_length;
    char guessed[27];
    char answer[255];
    char masked[255];
    int tries;
    int mistakes;
};

struct guess new_game(void);

void print_result(struct guess this_guess);


#endif // GAME_STATE_H_INCLUDED
