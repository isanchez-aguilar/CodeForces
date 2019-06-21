/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1133C - Balanced Team
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
	vector<Long> vals(n);

	for (int i = 0; i < n; ++i)
		cin >> vals[i];

	sort(begin(vals), end(vals));

	int ans = 1;

	for (int i = 0; i < n; ++i)
	{
		vector<Long>::iterator j = upper_bound(begin(vals), end(vals), vals[i] + 5ll);
		int currentMembers = distance(begin(vals) + i, j);
		
		ans = max(ans, currentMembers);
	}

	cout << ans << "\n";

	return 0;
}