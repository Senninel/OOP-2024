
#include <iostream>
#include "Array.h"
using namespace std;


int main()
{
	try
	{
		Array<int> arr(10);
		arr += 1;
		arr += 2;
		arr += 3;

		cout << "Array size: " << arr.GetSize() << endl;

		arr.Insert(1, 5);
		cout << "Elementul la indexul 1: " << arr[1] << endl;

		arr.Delete(1);
		cout << "Elementul la indexul 1 dupa stergere: " << arr[1] << endl;

		cout << arr[2] << " " << arr[1] << endl;

		arr.Insert(1, 10);
		///Afisare
		for (int i = 0;i < arr.GetSize();i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		arr.Sort();
		///Afisare dupa sortare
		for (int i = 0;i < arr.GetSize();i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

		if (arr.Find(1))
		{
			cout << "Am gasit elementul 1" << endl;
		}
		else
		{
			cout << "Nu am gasit elementul 1" << endl;
		}

		int gasit = arr.BinarySearch(2);
		if (gasit != -1)
			cout << "gasit la pozitia " << gasit << endl;
		else cout << "nu am gasit";

	}
	catch (const exception& e)
	{
		cout << "exceptie: " << e.what() << endl;
	}

	return 0;
}

