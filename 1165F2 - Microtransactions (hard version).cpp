/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1165F2 - Microtransactions (hard version)
*/
#include <bits/stdc++.h>

#define LAST_DAY 400000

using namespace std;

int n, m;
vector<int> k;
vector< pair<int, int> > sales;

inline bool isPossible(const int& maxDay)
{
	vector<int> lastSale(n, -1);

	for (int i = 0; i < m; ++i)
	{
		if (sales[i].first <= maxDay)
			lastSale[sales[i].second] = max(lastSale[sales[i].second], sales[i].first);
	}

	vector< vector<int> > salesCurrentDay(200001);

	for (int i = 0; i < n; ++i)
	{
		if (lastSale[i] != -1)
			salesCurrentDay[lastSale[i]].push_back(i);
	}

	int currentMoney = 0;
	vector<int> remaining = k;

	for (int day = 0; day <= maxDay; ++day)
	{
		++currentMoney;

		if (day <= 200000)
		{
			for (int typeSale : salesCurrentDay[day])
			{
				if (remaining[typeSale] <= currentMoney)
				{
					currentMoney -= remaining[typeSale];
					remaining[typeSale] = 0;
				}
				else
				{
					remaining[typeSale] -= currentMoney;
					currentMoney = 0;
					break;
				}
			}
		}
	}

	return 2 * accumulate(begin(remaining), end(remaining), 0) <= currentMoney;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	k = vector<int>(n);
	sales = vector< pair<int, int> >(m);

	for (int i = 0; i < n; ++i)
		cin >> k[i];

	for (int i = 0; i < m; ++i)
	{
		cin >> sales[i].first >> sales[i].second;
		
		--sales[i].first;
		--sales[i].second;
	}

	int leftDay = 0;
	int ans = LAST_DAY;
	int rightDay = LAST_DAY;

	while (leftDay <= rightDay)
	{
		const int middleDay = (leftDay + rightDay) / 2;

		if (isPossible(middleDay))
		{
			ans = middleDay;
			rightDay = middleDay - 1;
		}
		else
			leftDay = middleDay + 1;
	}

	cout << ans + 1 << "\n";

	return 0;
}