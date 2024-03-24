#pragma once
#include <stdio.h>
class Sort
{
	int* v;
	int n;
public:
	Sort(int n, int min, int max);
	Sort(int n, int a[]);
	Sort(int count, ...);
	Sort(char s[]);
	Sort();
	void InsertSort(bool ascendent = false);
	void QuickSort(bool ascendent =false, int st =0, int dr	= 0);
	void BubbleSort(bool ascendent = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
	int GetArrayLen();
};

