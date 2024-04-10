#include "Volvo.h"

double Volvo::getFuelCapacity()
{
    return 70.0;
}

double Volvo::getFuelConsumption()
{
    return 5.0;
}

double Volvo::getAverageSpeed(Weather weather)
{
    if (weather == Rain)
        return 80.0;
    else if (weather == Sunny)
        return 100.0;
    else return 70.0;
}

const char* Volvo::getName()
{
    return "Volvo";
}
