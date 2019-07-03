/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1183H - Subsequences (hard version)
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

const Long MAX_VAL = 1000000000001ll;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	Long k;
	string s;
	cin >> n >> k >> s;

	Long lastC[n][26];
	memset(lastC, -1, sizeof lastC);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 26 and i > 0; ++j)
				lastC[i][j] = lastC[i - 1][j];

		lastC[i][s[i] - 'a'] = i;
	}

	vector< vector<Long> > memo(n, vector<Long>(n));

	for (int i = 0; i < n; ++i)
		memo[i][1] = 1;

	for (int i = 2; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			for (int k = 0; k < 26; ++k)
			{
				if (lastC[j - 1][k] != -1)
					memo[j][i] = min(MAX_VAL, memo[j][i] + memo[lastC[j - 1][k]][i - 1]);
			}
		}
	}

	--k;
	Long ansCost = 0;

	for (int i = n - 1; i > 0 and k > 0; --i)
	{
		Long currentSubsequences = 0;

		for (int j = 0; j < 26; ++j)
		{
			if (lastC[n - 1][j] != -1)
				currentSubsequences += memo[lastC[n - 1][j]][i];
		}

		if (k <= currentSubsequences)
			currentSubsequences = k;

		ansCost += (n - i) * currentSubsequences;
		k -= currentSubsequences;
	}

	if (k == 1)
	{
		k = 0;
		ansCost += n;
	}

	if (k > 0)
		ansCost = -1;

	cout << ansCost << "\n";

	return 0;
}