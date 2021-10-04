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

void initStepCounters()
{
    // initialise all algorithms
    dummy_init();

    initAlgo();
}

void processStep(time_t time, accel_t x, accel_t y, accel_t z)
{
    dummy_process(time, x, y, z);

    processSample(time, x, y, z);
}

void printSteps(char *type, char *filename, long int groundTruth)
{
    long int steps = dummy_getSteps();
    printf("%s, dummy, %s, %ld, %ld\n", type, filename, steps, groundTruth);

    steps = getSteps();
    printf("%s, oxford, %s, %ld, %ld\n", type, filename, steps, groundTruth);
}

void resetStepCounters()
{
    resetSteps();
    resetAlgo();
}
