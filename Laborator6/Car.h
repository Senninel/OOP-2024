#pragma once
#include "Weather.h"
class Car
{
public:
	virtual double getFuelCapacity() = 0;
	virtual double getFuelConsumption() = 0;
	virtual double getAverageSpeed(Weather weather) = 0;
	virtual const char* getName() = 0;
};

