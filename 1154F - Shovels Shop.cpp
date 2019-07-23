/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1154F - Shovels Shop
*/
#include <bits/stdc++.h>

#define MAX_VAL 1000000000

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> prices(n);
	vector<int> offers(k + 1);

	for (int i = 0; i < n; ++i)
		cin >> prices[i];

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		if (x <= k)
			offers[x] = max(offers[x], y);
	}

	sort(begin(prices), end(prices));

	prices.resize(k);
	reverse(begin(prices), end(prices));

	vector<int> sumPrices(k + 1);

	for (int i = 1; i <= k; ++i)
		sumPrices[i] = sumPrices[i - 1] + prices[i - 1];

	vector<int> dp(k + 1, MAX_VAL);
	dp[0] = 0;

	for (int i = 0; i < k; ++i)
	{
		dp[i + 1] = min(dp[i + 1], dp[i] + prices[i]); 
		for (int j = 1; j <= k and i + j <= k; ++j)
		{
			if (offers[j] != 0)
				dp[i + j] = min(dp[i + j], dp[i] + sumPrices[i + j - offers[j]] - sumPrices[i]);
		}
	}

	cout << dp[k] << "\n";

	return 0;
}