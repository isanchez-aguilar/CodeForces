/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1118A - Water Buying
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	Long n, a, b, ans;

	cin >> q;
	while (q--)
	{
		cin >> n >> a >> b;
		double cA = double(a);
		double cB = double(b / 2.0);
		
		if (cA < cB)
			ans = n * a;
		else
			ans = (n - 2 * (n / 2)) * a + b * (n / 2);

		cout << ans << "\n";
	}

	return 0;
}