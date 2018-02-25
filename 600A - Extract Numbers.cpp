/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 600A - Extract Numbers
*/
#include <bits/stdc++.h>

using namespace std;

inline bool isNumber(string s)
{
	if (not s.length())
		return false;
	if (s[0] == '0')
		return s.length() == 1;
	
	for (int i = 0; i < s.length(); ++i)
	{
		if (not isdigit(s[i]))
			return false;
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	cin >> line;
	
	string aux = "";
	vector<string> word;
	vector<string> numbers;

	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == ',' or line[i] == ';')
		{
			if (isNumber(aux))
				numbers.push_back(aux);
			else
				word.push_back(aux);
			aux = "";

			continue;
		}

		aux += line[i];
	}

	if (isNumber(aux))
		numbers.push_back(aux);
	else
		word.push_back(aux);	

	cout << (numbers.size() < 1?"-\n":"\"");
	for (int i = 0; i < numbers.size(); ++i)
		cout << numbers[i] << (i + 1 == numbers.size()?"\"\n":",");

	cout << (word.size() < 1?"-\n":"\"");
	for (int i = 0; i < word.size(); ++i)
		cout << word[i] << (i + 1 == word.size()?"\"\n":",");

	return 0;
}