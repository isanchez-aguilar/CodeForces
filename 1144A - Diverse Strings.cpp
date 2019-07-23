/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1144A - Diverse Strings
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;

		sort(begin(s), end(s));

		bool good = true;
		char prev = s[0];

		for (int i = 1; i < s.length(); ++i)
		{
			if (prev + 1 != s[i])
			{
				good = false;
				break;
			}

			prev = s[i];
		}

		if (good)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}