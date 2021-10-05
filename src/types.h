#ifndef TYPES_H
#define TYPES_H

#include <inttypes.h>

// type for the accelerometer samples, this depends on your hardware
typedef int16_t accel_t;

// type used for time: warning the algorithm is not robust to roll-over of this variable
// example: a year worth of ms needs 35 bits, 32 bits allows you to store about 50 days of ms
typedef uint32_t sc_time_t;

// steps count type
// the size of this depends on what is the maximum number of steps you are willing to show and store
// example: is the step count is reset every 24h and one walks no more than 20k / day (reasonable) -> 16 bits should be enough
typedef uint16_t steps_t;

#endif