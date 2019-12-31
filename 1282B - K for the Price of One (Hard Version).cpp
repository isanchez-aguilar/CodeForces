/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1282B - K for the Price of One (Hard Version)
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;
using il = pair<int, Long>;

const Long INF = 5000000000;

il maxCmp(const il& a, const il& b)
{
	if (a.first == b.first)
	{
		if (a.second < b.second)
			return a;
		
		return b;
	}
	if (a.first > b.first)
		return a;
	return b;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		Long p;
		int n, k;
		cin >> n >> p >> k;

		vector<Long> prices(n);

		for (int i = 0; i < n; ++i)
			cin >> prices[i];

		sort(begin(prices), end(prices));

		vector<Long> accum(n);

		accum[0] = prices[0];

		for (int i = 1; i < n; ++i)
			accum[i] = prices[i] + prices[i - 1];

		il memo[n];

		fill(memo, memo + n, make_pair(0, INF));

		if (prices[0] <= p)
			memo[0] = {1, prices[0]};

		for (int i = 1; i < n; ++i)
		{
			memo[i] = memo[i - 1];
			
			if (i < k - 1)
			{

				if (memo[i].second + prices[i] <= p)
					memo[i] = {memo[i].first + 1, memo[i].second + prices[i]};
			}
			else
			{
				if (i == k - 1)
				{
					if (prices[i] <= p)
						memo[i] = {k, prices[i]};
				}
				else
				{
					il curr = memo[i - k];

					if (curr.second + prices[i] <= p)
					{ 
						curr.first += k;
						curr.second += prices[i];
					}

					memo[i] = maxCmp(memo[i], curr);
				}
			}
		}

		cout << memo[n - 1].first << "\n";
	}

	return 0;
}