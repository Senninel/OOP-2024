#include "Math.h"
#include <stdarg.h> 
#include <string.h>
#include <algorithm>
using namespace std;

int sumacif(char a, char b)
{
	return ((a - '0') + (b - '0'));
}
int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...)
{
	int suma = 0;
	va_list v1;
	va_start(v1, count);
	for (int i = 0;i < count;i++)
	{
		suma += va_arg(v1, int);
	}
	va_end(v1);
	return suma;
}
char* Math::Add(const char* s1, const char* s2)
{
	char* a = new char(strlen(s1));
	char* b = new char(strlen(s2));
	strcpy(a, s1);
	strcpy(b, s2);
	int n, m;
	n = strlen(a);
	m = strlen(b);
	int maxim = max(n, m);
	int minim = min(n, m);
	char* s = new char(maxim);
	int i = maxim - 1, j;
	for (j = minim - 1;j >= 0;j--)
	{
		if (n > m) b[i] = b[j];
		else a[i] = a[j];
		i--;
	}
	for (int i = 0;i < maxim - minim;i++)
	{
		if (n > m) b[i] = '0';
		else a[i] = '0';
	}
	int carry = 0;
	int number = 0;
	for (int i = maxim - 1;i >= 0;i--)
	{
		if (carry) number = 1;
		else number = 0;
		number += sumacif(a[i], b[i]);
		carry = number / 10;
		s[i] = (number % 10) + '0';
	}
	if (carry)
	{
		for (int i = maxim;i > 0;i--)
			s[i] = s[i - 1];
		s[0] = '1';
		s[maxim + 1] = '\0';
	}
	else s[maxim] = '\0';
	return s;

}
