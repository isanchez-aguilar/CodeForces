/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1144E - Median String
*/
#include <bits/stdc++.h>

#define UNCOLORED -1

using namespace std;
using Long = long long;

inline int toPosition(char c)
{
	return int(c - 'a');
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	string s, t;
	cin >> k >> s >> t;

	vector<int> ans(k + 1);

	for (int i = k; i > 0; --i)
	{
		ans[i] += toPosition(s[i - 1]) + toPosition(t[i - 1]);

		ans[i - 1] += ans[i] / 26;
		ans[i] %= 26;
	}

	for (int i = 0; i <= k; ++i)
	{
		int res = ans[i] % 2;
		ans[i] /= 2;

		if (i < k)
			ans[i + 1] += 26 * res;
	}

	for (int i = 1; i < k + 1; ++i)
		cout << char(ans[i] + 'a');

	return 0;
}