/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 71A - Way Too Long Words
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int testCases;
	cin >> testCases;
	while(testCases--)
	{
		string word;
		cin >> word;
		int length = word.length();
		if(length > 10)
			cout << word[0] << length - 2 << word[length - 1] << "\n";
		else
			cout << word << "\n";
	}
	return 0;
}