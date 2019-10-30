/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 80A - Panoramix's Prediction
*/
#include <bits/stdc++.h>

using namespace std;

inline bool isPrime(int n)
{
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	string ans = "YES";

	if (not isPrime(n) or not isPrime(m))
		ans = "NO";
	else
	{
		int nextP = n + 1;

		while (not isPrime(nextP))
			++nextP;

		if (nextP != m)
			ans = "NO\n";
	}

	cout << ans << "\n";

	return 0;
}