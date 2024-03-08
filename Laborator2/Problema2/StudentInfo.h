#pragma once
class StudentInfo
{
	char nume[55];
	float notaMate, notaEngleza, notaIstorie;
 public:
	 void SetName(char name[]);
	 void GetName(char *Name);
	 void SetMath(float x);
	 float GetMath();
	 void SetEnglish(float x);
	 float GetEnglish();
	 void SetHistory(float x);
	 float Gethistory();
	 float GetAverage();
};

