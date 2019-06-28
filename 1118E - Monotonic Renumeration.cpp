/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1118E - Monotonic Renumeration
*/
#include <bits/stdc++.h>

#define MOD 998244353

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	map<int, int> lastIndex;
	vector<int> lastPosition(n);

	for (int i = n - 1; i >= 0; --i)
	{
		if (lastIndex.count(a[i]) == 0)
			lastIndex[a[i]] = i;

		lastPosition[i] = lastIndex[a[i]];
	}

	int ans = 1;
	int maxIndex = -1;
	for (int i = 0; i < n - 1; ++i)
	{
		maxIndex = max(maxIndex, lastPosition[i]);

		if (maxIndex == i)
			ans = (2 * ans) % MOD;
	}

	cout << ans << "\n";

	return 0;
}