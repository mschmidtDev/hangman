#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include "time.h"

clock_t start_t, end_t;

// Function to start the timer at the beginning of the program
void start_timer();

// Function to end the timer
void end_timer();

// Function to return the current time used in program
double cur_timer();

#endif // TIMER_H_INCLUDED
