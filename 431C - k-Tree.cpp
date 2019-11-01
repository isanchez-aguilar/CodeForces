/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 431C - k-Tree
*/
#include <bits/stdc++.h>

#define MOD 1000000007ll

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, d;
	cin >> n >> k >> d;

	vector< vector<Long> > memo(n + 1, vector<Long>(2, 0));

	memo[0][0] = 1;
	memo[0][1] = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= min(k, i); ++j)
		{
			for (int f = 0; f < 2; ++f)
			{
				if (f == 1)
				{
					if (d <= j)
						memo[i][f] = (memo[i][f] + memo[i - j][0]) % MOD;
					else
						memo[i][f] = (memo[i][f] + memo[i - j][1]) % MOD;
				}
				else
				{
					memo[i][f] = (memo[i][f] + memo[i - j][0]) % MOD;
				}

				memo[i][1] %= MOD;
				memo[i][0] %= MOD;
			}
		}
	}

	cout << memo[n][1] << "\n";

	return 0;
}