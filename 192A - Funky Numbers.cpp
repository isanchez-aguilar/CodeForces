/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 192A - Funky Numbers
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll sum(ll n)
{
	return (n * (n + 1)) >> 1LL;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	ll m;
	ll x = 1;
	bool possible = false;

	while (n - sum(x) > 0)
	{
		if ((sum(x) << 1LL) == n)
		{
			possible = true;
			break;
		}

		ll l = 1;
		ll r = y;
		ll y = n - sum(x);
		
		while (l < r)
		{
			m = (l + r) >> 1LL;
			
			ll fm = sum(m);
			
			if (fm == y)
			{
				possible = true;
				break;
			}

			if (fm < y)
				l = m + 1;
			else
				r = m;
		}

		if (possible)
			break;

		++x;
	}

	if (possible)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}