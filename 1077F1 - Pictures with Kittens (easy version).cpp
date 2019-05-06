/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1077F1 - Pictures with Kittens (easy version)
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, k;
	cin >> n >> k >> x;

	vector<Number> beauty(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> beauty[i];

	vector< vector<Number> > memo(n + 1, vector<Number>(x + 1, -1));

	memo[0][0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int remaining = 1; remaining <= x; ++remaining)
		{
			for (int j = 1; j <= min(k, i); ++j)
			{
				if (memo[i - j][remaining - 1] != -1)
					memo[i][remaining] = max(memo[i][remaining], memo[i - j][remaining - 1] + beauty[i]);
			}

		}
	}

	Number ans = -1;

	for (int i = n - k + 1; i <= n; ++i)
		ans = max(ans, *max_element(begin(memo[i]), end(memo[i])));

	cout << ans << "\n";

	return 0;
}