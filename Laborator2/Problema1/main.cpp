#include <stdio.h>
#include "NumberList.h"

int main()
{
	NumberList v;
	v.Init();
	v.Add(10);
	v.Add(20);
	v.Add(5);
	v.Add(13);
	v.Print();
	v.Sort();
	v.Print();
	v.Init();
	v.Print();
}