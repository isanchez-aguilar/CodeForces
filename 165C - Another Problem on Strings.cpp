/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 165C - Another Problem on Strings
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	string s;
	cin >> k >> s;

	vector<Long> memo(s.length() + 1);
	
	memo[0] = 1;
	int ones = 0;
	Long ans = 0;

	for (int i = 0; i < int(s.length()); ++i)
	{
		ones += (s[i] == '1');

		if (k <= ones)
			ans += memo[ones - k];

		++memo[ones];
	}

	cout << ans << "\n";

	return 0;
}