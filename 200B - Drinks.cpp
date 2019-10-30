/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 200B - Drinks
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	double ans = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		ans += v;
	}

	ans /= double(n);

	cout << fixed << setprecision(4) << ans << "\n";

	return 0;
}