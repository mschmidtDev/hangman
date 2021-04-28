#include <time.h>
#include "timer.h"

// Start the timer
void start_timer()
{
    start_t = clock();
}

// End the timer
void end_timer()
{
    end_t = clock();
}

// Determine current time on timer
double cur_timer()
{
    clock_t cur_time = clock();

    double result = (double) (cur_time - start_t) / CLOCKS_PER_SEC;

    return result;
}
