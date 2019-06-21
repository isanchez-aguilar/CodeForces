/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1133E - K Balanced Teams
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<Long> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(begin(a), end(a));
	vector<int> people(n);

	for (int i = 0; i < n; ++i)
	{
		vector<Long>::iterator j = upper_bound(begin(a), end(a), a[i] + 5ll);
		int members = distance(begin(a) + i, j);
		people[i] = members;
	}

	vector< vector<Long> > memo(n + 1, vector<Long>(k + 1));

	for (int i = 0; i < n; ++i)
	{

		for (int j = 0; j <= k; ++j)
		{
			memo[i + 1][j] = max(memo[i + 1][j], memo[i][j]);

			if (j + 1 <= k)
				memo[i + people[i]][j + 1] = max(memo[i + people[i]][j + 1], memo[i][j] + people[i]); 
		}
	}

	cout << memo[n][k] << "\n";

	return 0;
}