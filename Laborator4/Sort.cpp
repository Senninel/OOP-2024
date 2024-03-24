#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdarg>

Sort::Sort(int n, int min, int max)
{
	time_t t;
	srand((unsigned)time(&t));
	this->v = new int[n+10];
	this->n = n;
	for (int i = 0;i < n;i++)
	{
		this->v[i] = min + rand() % ((max - min) + 1);
	}
}
Sort::Sort(int n, int a[])
{
	this->v = new int[n+10];
	this->n = n;
	for (int i = 0;i < n;i++)
		this->v[i] = a[i];
}
Sort::Sort(int count, ...)
{
	this->v = new int[count+10];
	this->n = count;
	va_list v;
	va_start(v,count);
	for (int i = 0;i < count;i++)
        this->v[i] = va_arg(v, int);
	va_end(v);
}

Sort::Sort(char s[])
{
    if (s[0] == '\0') return;
	int nr, i;
	int count = 1;
	for (i = 0;s[i] != '\0';i++)
		if (s[i] == ',') count++;
	this->v = new int[count + 10];
	this->n = count;
	nr = count = 0;
	for (i = 0;s[i] != '\0';i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			nr = nr * 10 + (s[i] - '0');
		else
		{
			v[count++] = nr;
			nr = 0;
		}
	}
	v[count++] = nr;
}
Sort::Sort() : v(new int[5] {10, 20, 30, 40, 50})
{
	this->n = 5;
}
void Sort::Print()
{
	for (int i = 0;i < this->n;i++)
		printf("%d ", v[i]);
	printf("\n");
}
int Sort::GetElementsCount()
{
	return this->n;
}
int Sort::GetElementFromIndex(int index)
{
	if (index < 1 || index > n)
	{
		printf("Nu ai specificat o pozitie corecta, eroare: ");
		return 404;
	}
	return this->v[index-1];
}
void Sort::InsertSort(bool ascendent) {
	for (int i = 1; i < this->n; i++) {
		int key = this->v[i];
		int j = i - 1;
		while (j >= 0 && ((ascendent && this->v[j] > key) || (!ascendent && this->v[j] < key))) {
			this->v[j + 1] = this->v[j];
			j = j - 1;
		}
		this->v[j + 1] = key;
	}
}
void Sort::BubbleSort(bool ascendent)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if ((ascendent &&v[j] > v[j + 1]) || (!ascendent && (v[j] < v[j+1])))
			{
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
}
int Pivot(int st, int dr, int a[], int ascendent)
{
	int i, j, piv;
	piv = a[st];
	i = st;
	for (j = st + 1; j <= dr; j++)
		if ((ascendent && a[j] <= piv) || (!ascendent && a[j] >= piv))
		{
			i++;
			int aux = a[i];
			a[i] = a[j];
			a[j] = aux;
		}
	int aux = a[st];
	a[st] = a[i];
	a[i] = aux;
	return i;
}

void Sort::QuickSort(bool ascendent,int st, int dr)
{
	int p = Pivot(st, dr, this->v,ascendent);
	if (st < p - 1) QuickSort(ascendent,st, p - 1);
	if (p + 1 < dr) QuickSort(ascendent,p + 1, dr);
}
int Sort::GetArrayLen()
{
	return this->n;
}