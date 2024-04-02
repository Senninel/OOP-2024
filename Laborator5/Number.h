#pragma once
class Number
{
	char* value = nullptr;
	int base = 0;
	int len = 0;
	public:
		Number(const char* value, int base); // where base is between 2 and 16
		~Number();

		// add operators and copy/move constructor
		Number(Number & n);
		Number(Number&& n);
		Number(int val);
		Number& operator = (char* s);
		Number& operator = (int val);
		bool operator>(Number& comp);
		bool operator>(int number);
		bool operator<(Number& comp);
		bool operator<(int number);
		bool operator==(Number& comp);
		bool operator==(int number);
		bool operator>=(Number& comp);
		bool operator>=(int number);
		bool operator<=(Number& comp);
		bool operator<=(int number);
		char& operator[](int index);
		friend Number operator+(Number& termen1,Number& termen2);
		friend Number operator+(Number& termen1, int val);
		friend Number operator-(Number& termen1, Number& termen2);
		friend Number operator-(Number& termen1, int val);
		Number& operator+=(Number& termen);
		Number& operator-=(Number& termen);
		Number& operator=(Number&& egal);
		Number& operator--();
		Number& operator--(int numar);
		void SwitchBase(int newBase);
		void Print();
		int  GetDigitsCount(); // returns the number of digits for the current number
		int  GetBase(); // returns the current base
		friend int ConvertToBase10(Number cvt);
};

