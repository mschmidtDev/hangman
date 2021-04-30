#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include "time.h"

clock_t start_t, end_t;

void start_timer();

void end_timer();

double cur_timer();

#endif // TIMER_H_INCLUDED
