#include "Number.h"
#include <stdio.h>

Number::Number(const char* value, int base)
{
	int length = 0;
	for (int i = 0;value[i] != '\0';i++) length++;
	this->len = length;
	this->value = new char[length+10];
	this->base = base;
	for (int i = 0;value[i] != '\0';i++)
		this->value[i] = value[i];
}
Number::Number(Number& n)
{
	this->len = n.len;
	this->base = n.base;
	this->value = new char[n.len];
	for (int i = 0;i < n.len;i++)
		this->value[i] = n.value[i];
}
Number::Number(Number&& n)
{
	this->len = n.len;
	this->base = n.base;
	this->value = new char[n.len];
	for (int i = 0;i < n.len;i++)
		this->value[i] = n.value[i];
	n.len = n.base = 0;
	delete[] n.value;
}
Number::Number(int val)
{
	this->base = 10;
	int cnt = 0, test = val;
	while (test)
	{
		cnt++;
		test /= this->base;
	}
	this->len = cnt;
	this->value = new char[cnt + 1];
	while (val)
	{
		this->value[--cnt] = (val % this->base) + '0';
		val /= this->base;
	}
}
Number& Number::operator = (char* s)
{
	int leng = 0;
	for(int i = 0;s[i] != '\0';i++) leng++;
	this->len = leng;
	this->base = 10;
	this->value = new char[leng];
	for (int i = len - 1;i >= 0;i--)
		this->value[i] = s[i];
		
	return(*this);
}
Number& Number::operator = (int val)
{
	int cnt = 0,test = val;
	while (test)
	{
		cnt++;
		test /= this->base;
	}
	this->len = cnt;
	this->value = new char[cnt+1];
	while (val)
	{
		this->value[--cnt] = (val % this->base) + '0';
		val /= this->base;
	}
	return(*this);
}
void Number::Print()
{
	for (int i = 0;i < this->len;i++)
		printf("%c", this->value[i]);
	printf("\n");

}
Number::~Number()
{
	if (len == 0) return;
	delete[] this->value;
}
int Number::GetDigitsCount()
{
	return this->len;
}
int Number::GetBase()
{
	return this->base;
}
char GetChar(int nr, int base)
{
	if (nr % base == 10) return 'A';
	if (nr % base == 11) return 'B';
	if (nr % base == 12) return 'C';
	if (nr % base == 13) return 'D';
	if (nr % base == 14) return 'E';
	if (nr % base == 15) return 'F';
	return (nr & base) + '0';
}
void Number::SwitchBase(int newBase)
{
	int number10 = ConvertToBase10(*this);
	int cnt, test;
	cnt = 0;
	test = number10;
	while (test)
	{
		cnt++;
		test /= newBase;
	}
	delete[] this->value;
	this->value = new char[cnt];
	this->base = newBase;
	this->len = cnt;
	while (number10)
	{
		this->value[--cnt] = GetChar(number10, newBase);
		number10 /= newBase;
	}
}
int GetValue(char c)
{
	if (c == 'A') return 10;
	if (c == 'B') return 11;
	if (c == 'C') return 12;
	if (c == 'D') return 13;
	if (c == 'E') return 14;
	if (c == 'F') return 15;
	return c - '0';
}
int ConvertToBase10(Number cvt)
{
	int p, number10;
	number10 = 0;
	p = 1;
	for (int i = cvt.len - 1;i >= 0;i--)
	{
		number10 = number10 + (p * GetValue(cvt.value[i]));
		p = p * cvt.base;
	}
	return number10;
}
bool Number::operator>(Number& comp)
{
	int n1 = ConvertToBase10(*this);
	int n2 = ConvertToBase10(comp);
	return n1 > n2;
}
bool Number::operator>(int number)
{
	int n1 = ConvertToBase10(*this);
	return n1 > number;
}
bool Number::operator>=(Number& comp)
{
	int n1 = ConvertToBase10(*this);
	int n2 = ConvertToBase10(comp);
	return n1 >= n2;
}
bool Number::operator>=(int number)
{
	int n1 = ConvertToBase10(*this);
	return n1 >= number;
}
bool Number::operator<(Number& comp)
{
	int n1 = ConvertToBase10(*this);
	int n2 = ConvertToBase10(comp);
	return n1 < n2;
}
bool Number::operator<(int number)
{
	int n1 = ConvertToBase10(*this);
	return n1 < number;
}
bool Number::operator<=(Number& comp)
{
	int n1 = ConvertToBase10(*this);
	int n2 = ConvertToBase10(comp);
	return n1 <= n2;
}
bool Number::operator<=(int number)
{
	int n1 = ConvertToBase10(*this);
	return n1 <= number;
}
bool Number::operator==(Number& comp)
{
	int n1 = ConvertToBase10(*this);
	int n2 = ConvertToBase10(comp);
	return n1 == n2;
}
bool Number::operator==(int number)
{
	int n1 = ConvertToBase10(*this);
	return n1 == number;
}
char& Number::operator[](int index)
{
	if (index < 0 || index >= this->len)
	{
		char c = '!';
		return c;
	}
	return this->value[index];
}
Number& Number::operator=(Number&& egal)
{
	this->base = egal.GetBase();
	this->len = egal.GetDigitsCount();
	delete[] this->value;
	this->value = new char[this->len];
	for (int i = 0;i < this->len;i++)
		this->value[i] = egal.value[i];
	return *this;
}

Number operator+(Number& termen1, Number& termen2)
{
	int n1 = ConvertToBase10(termen1);
	n1 += ConvertToBase10(termen2);
	Number suma = n1;
	if (termen1.GetBase() > termen2.GetBase()) suma.SwitchBase(termen1.GetBase());
	else suma.SwitchBase(termen2.GetBase());
	return suma;
}
Number operator+(Number& termen1, int val)
{
	int n1 = ConvertToBase10(termen1);
	n1 += val;
	Number suma = n1;
	suma.SwitchBase(termen1.GetBase());
	return suma;
}
Number operator-(Number& termen1, Number& termen2)
{
	int n1 = ConvertToBase10(termen1);
	int n2 = ConvertToBase10(termen2);
	Number dif = 0;
	if (n1 < n2)
		return dif;
	dif = n1 - n2;
	if (termen1.GetBase() > termen2.GetBase()) dif.SwitchBase(termen1.GetBase());
	else dif.SwitchBase(termen2.GetBase());
	return dif;
}
Number operator-(Number& termen1, int val)
{
	int n1 = ConvertToBase10(termen1);
	Number dif = 0;
	if (n1 < val) return dif;
	dif = n1 - val;
	dif.SwitchBase(termen1.GetBase());
	return dif;
}
Number& Number::operator+=(Number& termen)
{
	int n1 = ConvertToBase10(*this);
	n1 += ConvertToBase10(termen);
	int base = this->GetBase();
	*this = n1;
	if (base > termen.GetBase()) this->SwitchBase(base);
	else this->SwitchBase(termen.GetBase());
	return *this;
}
Number& Number::operator-=(Number& termen)
{
	int n1 = ConvertToBase10(*this);
	int n2 = ConvertToBase10(termen);
	int base = this->GetBase();
	if (n1 < n2) *this = 0;
	if (base > termen.GetBase()) this->SwitchBase(base);
	else this->SwitchBase(termen.GetBase());
	return *this;
}
Number& Number::operator--()
{
	for (int i = 0;i < this->len - 1;i++) this->value[i] = this->value[i + 1];
	this->len--;
	return *this;
}
Number& Number::operator--(int numar)
{
	if (this->len > 0)
	{
		this->value[this->len - 1] = '\0';
		this->len--;
	}
	return *this;
}
