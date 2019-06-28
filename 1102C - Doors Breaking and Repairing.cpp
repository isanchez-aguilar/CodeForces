/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1102C - Doors Breaking and Repairing
*/
#include <bits/stdc++.h>

using namespace std;
using Long  = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;

	int lessEqualThan = 0;

	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;

		if (val <= x)
			++lessEqualThan;
	}
	
	int ans = 0;

	if (x <= y)
		ans = int(ceil(double(lessEqualThan) / 2.0f));
	else
		ans = n;
	
	cout << ans << "\n";

	return 0;
}