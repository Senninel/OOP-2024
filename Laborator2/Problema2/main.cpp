#include <stdio.h>
#include "StudentInfo.h"
#include <string.h>
#include "global.h"

int main()
{
	StudentInfo s1;
	char s[150];
	strcpy_s(s, "andrei");
	s1.SetName(s);
	char nume[150];
	s1.GetName(nume);
	printf("%s \n", nume);
	s1.SetEnglish(5.5);
	printf("Nota la engleza este: %f \n",s1.GetEnglish());
	s1.SetHistory(6);
	printf("Nota la istorie este: %f\n", s1.Gethistory());
	s1.SetMath(6.5);
	StudentInfo s2;
	char numele[200];
	strcpy(numele, "aa");
	s2.SetName(numele);
	printf("Nota la mate este: %f \n", s1.GetMath());
	printf("Avg-ul este : %f \n", s1.GetAverage());
	printf("Comparere nume: %d \n", CompareByName(s1,s2));
	return 0;
}