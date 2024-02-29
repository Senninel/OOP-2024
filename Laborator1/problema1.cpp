#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
int Cvt(char s[])
{
	int numar = 0;
	for (int i = 0;s[i] != NULL; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') numar = numar * 10 + (s[i] - '0');
		else return 0;
	}
	return numar;
}
int main()
{
	int suma = 0, num;
	FILE* fp;
	if (fopen_s(&fp, "in.txt", "r") != 0)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else
	{
		char numar[200];
		while(fgets(numar, 100, fp))
		{
			num = Cvt(numar);
			suma += num;
		}
		printf("%d\n", suma);
		fclose(fp);
	}

}

