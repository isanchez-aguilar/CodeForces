/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 276B - Little Girl and Game
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	vector<int> freq(26);

	for (char c : s)
		++freq[c - 'a'];

	int oddBlocks = 0;

	for (int f : freq)
	{
		if (f % 2 == 1)
			++oddBlocks;
	}

	if (freq[s[0] - 'a'] == (int)s.length() or oddBlocks <= 1)
		cout << "First\n";
	else
	{
		if (oddBlocks % 2 == 0)
			cout << "Second\n";
		else
			cout << "First\n";
	}

	return 0;
}