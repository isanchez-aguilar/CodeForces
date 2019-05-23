/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1165E - Two Arrays and Sum of Functions
*/
#include <bits/stdc++.h>

#define MOD 998244353ll

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Long> b(n);
	vector<Long> a(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		a[i] *= (n - Long(i)) * Long(i + 1);
	}

	for (int i = 0; i < n; ++i)
		cin >> b[i];

	sort(begin(a), end(a));
	sort(begin(b), end(b), greater<Long>());

	Long ans = 0;

	for (int i = 0; i < n; ++i)
	{
		a[i] %= MOD;
		b[i] %= MOD;
		ans += (b[i] * a[i]) % MOD;
		ans %= MOD;
	}

	cout << ans << "\n";

	return 0;
}