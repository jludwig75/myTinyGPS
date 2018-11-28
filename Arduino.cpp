#include "Arduino.h"

#include <time.h>


unsigned long millis()
{
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    return spec.tv_sec * 1000 + (spec.tv_nsec / 1000000);
}

float radians(float degrees)
{
    return (M_PI * degrees) / 180.0;
}

float degrees(float radians)
{
    return (180.0 * radians) / M_PI;
}

float sq(float value)
{
    return value * value;
}
