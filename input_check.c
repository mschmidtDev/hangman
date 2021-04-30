#include "input_check.h"

// Checks user input for validity (returns 1 if input is valid, 0 if not)
int check_input(char input)
{
    if (input >= 'a' && input <= 'z') {
        return 1;
    } else if (input >= 'A' && input <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}
