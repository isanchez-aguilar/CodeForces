/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1183B - Equalize Prices
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;;
	cin >> q;

	while (q--)
	{
		Long n, k;
		cin >> n >> k;

		Long minB = 1000000000;
		vector<Long> vals(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> vals[i];
			
			minB = min(minB, k + vals[i]);
		}

		for (int i = 0; i < n; ++i)
		{
			if (abs(vals[i] - minB) > k)
			{
				minB = -1;
				break;
			}
		}

		cout << minB << "\n";
	}

	return 0;
}