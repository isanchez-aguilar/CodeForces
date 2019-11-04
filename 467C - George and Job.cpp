/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 467C - George and Job
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<Long> vals(n);
	vector<Long> accum(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vals[i];
		accum[i] = vals[i];

		if (i > 0)
			accum[i] += accum[i - 1];
	}

	vector< vector<Long> > memo(n, vector<Long>(k + 1, -1000000000));
	
	for (int i = 0; i < n; ++i)
		memo[i][0] = 0;


	memo[m - 1][1] = accum[m - 1];

	for (int i = m; i < n; ++i)
	{
		for (int j = k; j > 0; --j)
		{ 
			memo[i][j] = max(memo[i - 1][j], 0ll);
			memo[i][j] = max(memo[i][j], memo[i - m][j - 1] + (accum[i] - accum[i - m]));
		}
	}

	cout << memo[n - 1][k] << "\n";

	return 0;
}