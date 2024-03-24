#include <stdio.h>
#include "Sort.h"


using namespace std;

int main()
{
	char test[105] = "10,30,20,15";
	Sort v = Sort(test);
	v.Print();
	Sort c = Sort();
	c.Print();
	return 0;
}