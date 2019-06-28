/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1118D - Coffee and Coursework (Hard Version)
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Long n, m;
	cin >> n >> m;

	vector<Long> vals(n);

	for (Long i = 0; i < n; ++i)
	{
		cin >> vals[i];
	}

	Long ans = -1;

	if (accumulate(begin(vals), end(vals), 0) >= m)
	{
		ans = 0;
		Long currentCup = 0;
		sort(begin(vals), end(vals), greater<Long>());

		Long l = 1;
		Long r = n;
		
		while (l <= r)
		{
			Long total = 0;
			Long middle = (l + r) / 2;

			for (int i = 0; i < n; ++i)
				total += max(vals[i] - i / middle, 0ll);

			if (m <= total)
			{
				ans = middle;
				r = middle - 1;
			}
			else
				l = middle + 1;
		}

	}

	cout << ans << "\n";

	return 0;
}