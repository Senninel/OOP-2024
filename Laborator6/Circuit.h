#pragma once
#include "Car.h"
class Circuit
{
public:
	double length;
	Weather weather;
	Car** cars;
	int count, capacity;
	double* rankings;
	const char** carnames;
	Circuit();
	~Circuit();
	void SetLength(double length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};



