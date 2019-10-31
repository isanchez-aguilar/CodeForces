/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 493C - Vasya and Basketball
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<Long> team1(n);

	for (int i = 0; i < n; ++i)
		cin >> team1[i];

	int m;
	cin >> m;

	vector<Long> team2(m);

	for (int i = 0; i < m; ++i)
		cin >> team2[i];

	vector< pair<Long, short> > throws(n + m);

	for (int i = 0; i < n; ++i)
		throws[i] = {team1[i], 0};

	for (int i = 0; i < m; ++i)
		throws[i + n] = {team2[i], 1};

	sort(begin(throws), end(throws), greater< pair<Long, short> >());

	int i = 0;
	Long maxDif = 2 * (n - m);
	vector<Long> ans = {2 * n, 2 * m};
	vector<Long> currScore = ans;

	while (i < n + m)
	{
		Long d = throws[i].first;

		while (i < n + m and d == throws[i].first)
		{
			++currScore[throws[i].second];
			++i;
		}
	
		Long dif = currScore[0] - currScore[1];
		
		if (maxDif <= dif)
		{
			if (maxDif == dif)
				ans = max(ans, currScore);
			else
			{
				ans = currScore;
				maxDif = dif;
			}
		}
	}

	cout << ans[0] << ":" << ans[1] << "\n";

	return 0;
}