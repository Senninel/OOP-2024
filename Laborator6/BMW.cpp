#include "BMW.h"

double BMW::getFuelCapacity()
{
    return 65.0;
}

double BMW::getFuelConsumption()
{
    return 6.0;
}

double BMW::getAverageSpeed(Weather weather)
{
    if (weather == Rain)
        return 90.0;
    else if (weather == Sunny)
        return 120.0;
    else return 80.0;
}

const char* BMW::getName()
{
    return "BMW";
}
