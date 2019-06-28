/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1183C - Computer Game
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	Long n, k, a, b;
	cin >> q;

	while (q--)
	{
		cin >> k >> n >> a >> b;

		Long l = 0;
		Long r = n;
		Long ans = -1;

		while (l <= r)
		{
			Long m = (l + r) / 2;
			Long total = a * m + (n - m) * b;

			if (total < k)
			{
				l = m + 1;
				ans = max(ans, m);
			}
			else
				r = m - 1;
		}

		cout << ans << "\n";
	}
	return 0;
}