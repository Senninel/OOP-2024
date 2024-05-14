#include<fstream>
#include<map>
#include<queue>
#include<string>
#include<iostream>

using namespace std;

class Compare {
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2) 
	{
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return true;
		return false;
	}
};

int litera(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
	return 0;
}
int main()
{
	string s;
	ifstream myFile("input.txt");
	if (!myFile)
	{
		printf("Eroare deschidere fisier");
		return 0;
	}
	if (!getline(myFile, s))
	{
		printf("Eroare citire");
		return 0;
	}
	map<string, int> m;
	int i, j;
	i = j = 0;
	while (j != s.length())
	{
		if ((s[j] == '!' || s[j] == ' ' || s[j] == ',' || s[j] == '?' || s[j] == '.') &&
			litera(s[j - 1]) && j > 0)
		{
			string cuv = s.substr(i, (j - i));
			if (m.count(cuv) != 0)
			{
				m[cuv] += 1;
			}
			else m[cuv] = 1;
			i = j;
		}
		if (litera(s[j]) && j >0 &&
			(s[j - 1] == '!' || s[j - 1] == ' ' || s[j - 1] == ',' || s[j - 1] == '?' || s[j - 1] == '.'))
			i = j;
		j++;
	}
	string cuv = s.substr(i, (j - i));
	if (m.count(cuv) != 0)
	{
		m[cuv] += 1;
	}
	else m[cuv] = 1;
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> Q;
	for (auto a = m.begin(); a != m.end(); a++)
		Q.push(pair<string, int>(a->first, a->second));
	while (!Q.empty())
	{
		printf("cuvantul %s apare de %d ori \n", Q.top().first.c_str(), Q.top().second);
		Q.pop();
	}
	return 0;
}
