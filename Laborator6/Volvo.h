#pragma once
#include "Car.h"
class Volvo : public Car
{
	double getFuelCapacity() override;
	double getFuelConsumption() override;
	double getAverageSpeed(Weather weather) override;
	const char* getName() override;
};

