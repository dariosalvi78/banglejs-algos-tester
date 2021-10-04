#include "../../types.h"

#ifndef DUMMY_H
#define DUMMY_H

void dummy_init();
void dummy_process(time_t time, accel_t x, accel_t y, accel_t z);
int dummy_getSteps();
void dummy_reset();

#endif