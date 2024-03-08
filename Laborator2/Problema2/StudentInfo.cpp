#include "StudentInfo.h"
#include <stdio.h>
#include <string.h>

void StudentInfo::SetName(char name[])
{
	strcpy_s(this->nume, name);
}
void StudentInfo::GetName(char* Name)
{
	strcpy(Name, this->nume);
}
void StudentInfo::SetMath(float x)
{
	if (x < 1 || x > 10) return;
	this->notaMate = x;
}
float StudentInfo::GetMath()
{
	return this->notaMate;
}
void StudentInfo::SetEnglish(float x)
{
	if (x < 1 || x > 10) return;
	this->notaEngleza = x;
}
float StudentInfo::GetEnglish()
{
	return this->notaEngleza; 
}
void StudentInfo::SetHistory(float x)
{
	if (x < 1 || x > 10) return;
	this->notaIstorie = x;
}
float StudentInfo::Gethistory()
{
	return this->notaIstorie;
}

float StudentInfo::GetAverage()
{
	float avg = 0;
	avg += this->notaEngleza;
	avg += this->notaIstorie;
	avg += this->notaMate;
	avg = avg / (float)3;
	return avg;
}