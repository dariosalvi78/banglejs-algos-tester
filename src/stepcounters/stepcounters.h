#ifndef STEPCOUNTERS_H
#define STEPCOUNTERS_H

#include "../types.h"

/**
 * Initialises the step counter algorithms
 */
void initStepCounters();

/**
 * Processess acceleration, passing x, y and z to all algorithms
 */
void processStep(time_t time, accel_t x, accel_t y, accel_t z);

/**
 * Prints the results of the step counting process for all algoritms
 */
void printSteps(char *type, char *filename, long int groundTruth);

/**
 * Resets step counters.
 */
void resetStepCounters();

#endif