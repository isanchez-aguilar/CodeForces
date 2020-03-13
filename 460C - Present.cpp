/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 460C - Present
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

Long m;
int n, w;
vector<Long> a;
vector<Long> applied;

inline bool haveThisMin(const Long& d)
{
	Long remaining = m;
	Long currApplied = 0;
	fill(begin(applied), end(applied), 0);
	
	for (int i = 0; i < n; ++i)
	{
		if (i - w >= 0)
			currApplied -= applied[i - w];

		if (d - (a[i] + currApplied) > 0)
		{
			applied[i] += d - (a[i] + currApplied);
			remaining -= applied[i];
			currApplied += applied[i];
		}
	}

	return remaining >= 0;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> w;

	a.resize(n);
	applied.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	Long l = *min_element(begin(a), end(a));
	Long r = *max_element(begin(a), end(a)) + m + 1;
	
	Long ans = l;

	while (l <= r)
	{
		Long currMinHeight = (l + r) / 2ll;

		if (haveThisMin(currMinHeight))
		{
			ans = currMinHeight;
			l = currMinHeight + 1;
		}
		else
			r = currMinHeight - 1;
	}

	cout << ans << "\n";

	return 0;
}