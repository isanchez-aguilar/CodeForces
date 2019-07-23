/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1154D - Walking Robot
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, b, a;
	cin >> n >> b >> a;

	int maxCap = a;
	vector<int> road(n);

	for (int i = 0; i < n; ++i)
		cin >> road[i];

	int ans = 0;

	for (int i = 0; i < n and (a > 0 or b > 0); ++i)
	{
		++ans;

		if (b == 0)
			--a;
		else if (a == 0)
			--b, a += road[i];
		else if (road[i] == 1 and a < maxCap)
			--b, ++a;
		else
			--a;

		a = min(a, maxCap);
	}

	cout << ans << "\n";

	return 0;
}