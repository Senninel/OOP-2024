#include "Seat.h"

double Seat::getFuelCapacity()
{
    return 50.0;
}

double Seat::getFuelConsumption()
{
    return 4.0;
}

double Seat::getAverageSpeed(Weather weather)
{
    if (weather == Rain)
        return 70.0;
    else if (weather == Sunny)
        return 90.0;
    else return 60.0;
}

const char* Seat::getName()
{
    return "Seat";
}
