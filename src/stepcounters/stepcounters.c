#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stepcounters.h"

// dummy algo
#include "dummy-counter/dummy.h"

// Oxford algo
#include "oxford-step-counter/scoringStage.h"
#include "oxford-step-counter/detectionStage.h"
#include "oxford-step-counter/postProcessingStage.h"
#include "oxford-step-counter/StepCountingAlgo.h"

// espruino
#include "espruino/espruino.h"

steps_t espruino_counter = 0;

void initStepCounters()
{
    // initialise all algorithms
    dummy_init();

    initAlgo();

    // espruino
    espruino_counter = 0;
    espruino_stepcount_init();
}

void processStep(sc_time_t time, accel_t x, accel_t y, accel_t z)
{
    dummy_process(time, x, y, z);

    processSample(time, x, y, z);

    espruino_counter += espruino_stepcount_new(x * x + y * y + z * z);
}

void printSteps(char *type, char *filename, long int groundTruth)
{
    long int steps = dummy_getSteps();
    printf("%s, dummy, %s, %ld, %ld\n", type, filename, steps, groundTruth);

    steps = getSteps();
    printf("%s, oxford, %s, %ld, %ld\n", type, filename, steps, groundTruth);

    printf("%s, espruino, %s, %ld, %ld\n", type, filename, espruino_counter, groundTruth);
}

void resetStepCounters()
{
    resetSteps();
    resetAlgo();
    espruino_counter = 0;
}
