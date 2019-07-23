/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1154C - Gourmet Cat
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> food(3);
	int weeks = INT_MAX;
	const int amountType[3] = {3, 2, 2};
	const int typeDay[7] = {0, 1, 2, 0, 2, 1, 0};

	for (int i = 0; i < 3; ++i)
	{
		cin >> food[i];
		weeks = min(weeks, food[i] / amountType[i]);
	}

	for (int i = 0; i < 3; ++i)
		food[i] -= weeks * amountType[i];

	int ans = 0;

	for (int i = 0; i < 7; ++i)
	{
		int days = 0;
		int currentDay = i;
		vector<int> auxFood = food;

		while (auxFood[typeDay[currentDay]] > 0)
		{
			++days;
			--auxFood[typeDay[currentDay]];
			currentDay = (currentDay + 1) % 7;
		}

		ans = max(ans, 7 * weeks + days);
	}

	cout << ans << "\n";

	return 0;
}