#include "Fiat.h"

double Fiat::getFuelCapacity()
{
    return 45.0;
}

double Fiat::getFuelConsumption()
{
    return 3.5;
}

double Fiat::getAverageSpeed(Weather weather)
{
    if (weather == Rain)
        return 60.0;
    else if (weather == Sunny)
        return 80.0;
    else return 50.0;
}

const char* Fiat::getName()
{
    return "Fiat";
}

