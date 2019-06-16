/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1176A - Divide it!
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

inline Long simulation(Long& n)
{
	Long ans = 0;

	while (n % 5 == 0)
	{
		ans += 3;
		n /= 5;
	}

	while (n % 3 == 0)
	{
		ans += 2;
		n /= 3;
	}

	while (n % 2 == 0)
	{
		n >>= 1ll;
		++ans;
	}

	if (n != 1)
		ans = -1;

	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	while (q--)
	{
		Long n;
		cin >> n;

		Long ans = simulation(n);

		cout << ans << "\n";
	}

	return 0;
}