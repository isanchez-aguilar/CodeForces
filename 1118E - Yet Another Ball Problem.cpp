/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1118E - Yet Another Ball Problem
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Long n, k;
	cin >> n >> k;

	if (k * (k - 1) < n)
		cout << "NO\n";
	else
	{
		cout << "YES\n";

		int g = 0;
		for (int i = 0; i < n; ++i)
		{
			g += (i % k == 0);
			cout << i % k + 1 << " " << (g + i % k) % k + 1 << "\n";
		}
	}

	return 0;
}