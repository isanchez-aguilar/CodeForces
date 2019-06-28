/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1118B - Tanya and Candies
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> vals(n);

	int sumOdds = 0;
	int sumEvens = 0;
	int sumPrevOdds = 0;
	int sumPrevEvens = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> vals[i];

		if (i % 2 == 0)
			sumOdds += vals[i];
		else
			sumEvens += vals[i];
	}

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		int f1, f2;

		if (i % 2 == 0)
		{
			f2 = 0;
			f1 = vals[i];
			sumOdds -= vals[i];
			sumPrevEvens += vals[i];
		}
		else
		{
			f1 = 0;
			f2 = vals[i];
			sumEvens -= vals[i];
			sumPrevOdds += vals[i];
		}

		if (sumEvens + sumPrevEvens - f1 == sumOdds + sumPrevOdds - f2)
			++ans;
	}

	cout << ans << "\n";

	return 0;
}