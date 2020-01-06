/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 508C - Anya and Ghosts
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, t, r;
	cin >> m >> t >> r;

	vector<int> ghosts(m);

	for (int i = 0; i < m; ++i)
		cin >> ghosts[i];

	sort(begin(ghosts), end(ghosts));

	set<int> lights;
	vector<bool> used(801);

	int ans = 0;
	int i = m - 1;

	while (i >= 0)
	{
		if (i + 1 < m)
		{
			for (int j = ghosts[i]; j <= ghosts[i + 1]; ++j)
				lights.erase(j + 301);
		}

		lights.erase(ghosts[i]);
		
		for (int j = t; j > 0 and lights.size() < r; --j)
		{
			const int currCandleT = ghosts[i] - j + 301;

			if (not used[currCandleT] and currCandleT - 301 + t > ghosts[i] - 1)
			{
				++ans;
				used[currCandleT] = true;
				lights.insert(currCandleT);
			}
		} 

		if (lights.size() < r)
		{
			ans = -1;
			break;
		}

		--i;
	}

	cout << ans << "\n";

	return 0;
}