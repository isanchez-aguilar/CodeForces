/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1151E - Number of Components
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

	vector<Long> nodes(n);

	for (int i = 0; i < n; ++i)
		cin >> nodes[i];

	Long ans = nodes[0] * (n - nodes[0] + 1);

	for (int i = 1; i < n; ++i)
	{
		if (nodes[i - 1] < nodes[i])
			ans += (nodes[i] - nodes[i - 1]) * (n - nodes[i] + 1);
		else
			ans += nodes[i] * (nodes[i - 1] - nodes[i]);
	}

	cout << ans << "\n";

	return 0;
}