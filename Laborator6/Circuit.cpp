#include "Circuit.h"
#include <stdio.h>

Circuit::Circuit()
{
	capacity = 10;
	count = 0;
	cars = new Car*[capacity];
	carnames = new const char* [capacity];
}

Circuit::~Circuit()
{
	delete[] cars;
}

void Circuit::SetLength(double length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
	if (count == capacity)
	{
		capacity *= 2;
		Car** newcars = new Car*[capacity];
		for (int i = 0; i < count; i++)
			newcars[i] = cars[i];
		delete[] cars;
		cars = newcars;
	}
	cars[count] = car;
	carnames[count] = car->getName();
	count++;
}


void Circuit::Race()
{
	double x;
	rankings = new double[count];
	for (int i = 0; i < count; i++)
	{
		x = (cars[i]->getFuelConsumption() * length) / 100;
		if (x > cars[i]->getFuelCapacity())
			rankings[i] = -1;
		else
		{
			x = (60 * length) / cars[i]->getAverageSpeed(weather);
			rankings[i] = x;
		}
	}
	
	for(int i = 0; i < count - 1; i++)
		for(int j = i + 1; j < count; j++)
			if (rankings[i] > rankings[j])
			{
				double aux = rankings[i];
				rankings[i] = rankings[j];
				rankings[j] = aux;

				const char* p = carnames[i];
				carnames[i] = carnames[j];
				carnames[j] = p;
			}
}

void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < count; i++)
		if(rankings[i] != -1)
			printf("%s : %f\n", carnames[i], rankings[i]);
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < count; i++)
		if (rankings[i] == -1)
			printf("%s did not finish\n", carnames[i]);
}
