#include "RangeRover.h"

double RangeRover::getFuelCapacity()
{
    return 80.0;
}

double RangeRover::getFuelConsumption()
{
    return 8.0;
}

double RangeRover::getAverageSpeed(Weather weather)
{
    if (weather == Rain)
        return 70.0;
    else if (weather == Sunny)
        return 90.0;
    else return 80.0;
}

const char* RangeRover::getName()
{
    return "RangeRover";
}
