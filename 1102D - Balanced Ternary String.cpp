/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1102D - Balanced Ternary String
*/
#include <bits/stdc++.h>

using namespace std;
using Long  = long long;

inline void solve(string& s)
{
	vector<int> freq(3);
	vector<int> ignored(3);
	const int n = s.length();
	const int equalParts = n / 3;

	for (char c : s)
		++freq[c - '0'];

	for (int i = 0; i < n; ++i)
	{

		short d = s[i] - '0';
		
		for (int j = 0; j < 3 and equalParts < freq[d]; ++j)
		{
			if (j != d and freq[j] < equalParts)
			{
				if (d < j and ignored[d] < equalParts)
					break;

				s[i] = char(j + '0');
				--freq[d];
				++freq[j];
				d = j;
			}
		}

		++ignored[d];
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	solve(s);

	cout << s << "\n";

	return 0;
}