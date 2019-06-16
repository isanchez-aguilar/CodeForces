/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1108C - Nice Garland
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	string ansS = "";
	string block = "BGR";
	int minRecolour = 1000000;

	do
	{
		int diff = 0;
	
		for (int i = 0; i < n; i += 3)
		{
			for (int j = 0; i + j < n and j < 3; ++j)
			{
				if (s[i + j] != block[j])
					++diff;
			}
		}

		if (diff < minRecolour)
		{
			ansS = "";
			minRecolour = diff;
			
			for (int i = 0; i < n; ++i)
				ansS += block[i % 3];
		}
	} while (next_permutation(begin(block), end(block)));

	cout << minRecolour << "\n" << ansS << "\n";

	return 0;
}