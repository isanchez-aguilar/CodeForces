/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 347B - Fixed Points
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> vals(n);

	for (int i = 0; i < n; ++i)
		cin >> vals[i];

	int ans = 0;
	bool operation = true;

	for (int i = 0; i < n; ++i)
	{
		if (vals[i] == i)
			++ans;
		else if (operation and vals[vals[i]] == i)
		{
			++ans;
			operation = false;
			swap(vals[i], vals[vals[i]]);
		}
	}

	if (ans < n and operation)
		++ans;

	cout << ans << "\n";

	return 0;
}