/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1108D - Diverse Garland
*/
#include <bits/stdc++.h>

using namespace std;

const string colours = "BGR";

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	string ansS = "";
	int minRecolour = 0;

	ansS += s[0];

	for (int i = 1; i < n; ++i)
	{
		if (s[i] == ansS[i - 1])
		{
			++minRecolour;

			if (i == n - 1)
			{
				for (char c : colours)
				{
					if (c != ansS[i - 1])
					{
						ansS += c;
						break;
					}
				}
			}
			else
			{
				for (char c : colours)
				{
					if (c != ansS[i - 1] and c != s[i + 1])
					{
						ansS += c;
						break;
					}
				}
			}
		}
		else
			ansS += s[i];
	}

	cout << minRecolour << "\n" << ansS << "\n";

	return 0;
}