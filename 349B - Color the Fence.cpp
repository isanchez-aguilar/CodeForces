/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 349B - Color the Fence
*/
#include <bits/stdc++.h>

using namespace std;

inline bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second > b.second;

	return a.first < b.first;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int v;
	cin >> v;

	vector< pair<int, int> > costs(9);

	for (int i = 1; i < 10; ++i)
	{
		int c;
		cin >> c;
		costs[i - 1] = {c, i};
	}

	sort(begin(costs), end(costs), cmp);

	int f = v / costs[0].first;

	string ans = "";

	if (f == 0)
		ans = "-1";
	else
	{
		int r = v % costs[0].first;

		for (int i = 0; i < f; ++i)
		{
			int cost = costs[0].first;
			int digit = costs[0].second;

			for (int j = 0; j < 9; ++j)
			{
				if (digit < costs[j].second and costs[j].first <= r + costs[0].first)
				{
					cost = costs[j].first;
					digit = costs[j].second;
				}
			}

			ans += char(digit + '0');
			if (digit != costs[0].second)
				r -= cost - costs[0].first;
		}
	}

	cout << ans << "\n";

	return 0;
}