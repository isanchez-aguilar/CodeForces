/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 155A - I_love_%username%
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

	int minV, maxV;
	cin >> minV;

	maxV = minV;
	int ans = 0;

	for (int i = 1; i < n; ++i)
	{
		int v;
		cin >> v;

		if (v < minV)
			++ans, minV = v;
		else if (maxV < v)
			++ans, maxV = v;
	}

	cout << ans << "\n";

	return 0;
}