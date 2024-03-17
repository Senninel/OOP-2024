#include <stdio.h>
#include "Canvas.h"
#include <iostream>

using namespace std;

int main()
{
	Canvas nr1 = Canvas(40,40);
	nr1.DrawRect(5, 4, 10, 8, '*');
	nr1.FillRect(5, 4, 10, 8, '*');
	nr1.SetPoint(15, 15, '/');
	nr1.DrawCircle(20, 20, 5, '*');
	nr1.FillCircle(20, 20, 5, '*');
	nr1.DrawLine(10, 10, 20, 20, '*');
	nr1.Print();

}