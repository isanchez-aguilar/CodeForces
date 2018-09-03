/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 448D - Multiplication Table
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll m;

inline ll getNumberElementLower(ll p)
{
	--p;
	ll i = m;
	ll totalElements = 0;

	while (i > 0 and p / i < n)
	{
		totalElements += p / i;
		--i;
	}
	
	return totalElements + i * n;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll k;
	cin >> n >> m >> k;

	ll l = 1;
	ll r = n * m + 1;
	
	while (l < r)
	{
		ll m = (l + r) >> 1LL;

		if (getNumberElementLower(m) < k)
			l = m + 1;
		else
			r = m;
	}

	cout << l - 1 << "\n";

	return 0;
}