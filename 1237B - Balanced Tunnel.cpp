/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1237B - Balanced Tunnel
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> enter(n), exit(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> enter[i];
		--enter[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> exit[i];
		--exit[i];
	}

	vector<int> 	timeExit(n), posId(n);

	for (int i = 0; i < n; ++i)
		posId[exit[i]] = i;

	for (int i = 0; i < n; ++i)
		timeExit[i] = posId[enter[i]];

	int ans = 0;
	int maxTime = -1;

	for (int i = 0; i < n; ++i)
	{
		if (maxTime < timeExit[i])
			maxTime = timeExit[i];
		else
			++ans;
	}

	cout << ans << "\n";

	return 0;
}