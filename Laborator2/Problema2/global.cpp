#include "global.h"
#include <stdio.h>
#include <string.h>

int CompareByName(StudentInfo s1, StudentInfo s2)
{
	char nume1[100] = "";
	char nume2[100] = "";
	s1.GetName(nume1);
	s2.GetName(nume2);
	return strcmp(nume1, nume2);
}
int CompareByMath(StudentInfo* s1, StudentInfo* s2)
{
	if (s1->GetMath() > s2->GetMath()) return 1;
	if (s1->GetMath() < s2->GetMath()) return -1;
	return 0;
}
int CompareByEnglish(StudentInfo* s1, StudentInfo* s2)
{
	if (s1->GetEnglish() > s2->GetEnglish()) return 1;
	if (s1->GetEnglish() < s2->GetEnglish()) return -1;
	return 0;
}
int CompareByHistory(StudentInfo* s1, StudentInfo* s2)
{
	if (s1->Gethistory() > s2->Gethistory()) return 1;
	if (s1->Gethistory() < s2->Gethistory()) return -1;
	return 0;
}
int CompareByAverage(StudentInfo* s1, StudentInfo* s2)
{
	if (s1->GetAverage() > s2->GetAverage()) return 1;
	if (s2->GetAverage() > s2->GetAverage()) return -1;
	return 0;
}
