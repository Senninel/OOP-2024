#include <stdio.h>
#include "Math.h"
#include <iostream>

using namespace std;

int main()
{
	Math obj;
	cout << obj.Add(5, 7) << " ";
	cout << obj.Add("5150", "5000");
}