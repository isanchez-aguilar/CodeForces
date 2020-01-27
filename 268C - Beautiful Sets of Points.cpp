/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 268C - Beautiful Sets of Points
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int x = 0, y = m;

	cout << min(n + 1, m + 1) << "\n";

	while (x <= n and y >= 0)
	{
		cout << x << " " << y << "\n";
		--y;
		++x;
	}

	return 0;
}