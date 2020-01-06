/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 371C - Hamburgers
*/
#include <iostream>
#include <string>

using namespace std;
using Long = long long;

const Long INF = 10000000000001ll;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string ingredients;
	cin >> ingredients;

	Long nb, ns, nc;
	cin >> nb >> ns >> nc;

	Long pb, ps, pc;
	cin >> pb >> ps >> pc;

	Long money;
	cin >> money;

	Long b = 0, s = 0, c = 0;

	for (const char& i : ingredients)
	{
		if (i == 'B')
			++b;
		else if (i == 'S')
			++s;
		else
			++c;
	}

	const Long enableBurgers = min(b?nb / b:INF, min(s?ns / s:INF, c?nc / c:INF));
	
	Long ans = enableBurgers;
	Long maxBurgers = INF;
	Long minBurgers = enableBurgers + 1;

	nb -= enableBurgers * b;
	ns -= enableBurgers * s;
	nc -= enableBurgers * c;

	while (minBurgers <= maxBurgers)
	{
		Long currBurgers = (minBurgers + maxBurgers) / 2ll;

		Long remainingBurgers = currBurgers - enableBurgers;

		Long currMoney = money;
		currMoney -= max(0ll, pb * (b * remainingBurgers - nb));
	
		if (currMoney >= 0)
			currMoney -= max(0ll, ps * (s * remainingBurgers - ns));

		if (currMoney >= 0)
			currMoney -= max(0ll, pc * (c * remainingBurgers - nc));

		if (currMoney >= 0)
		{
			ans = currBurgers;
			minBurgers = currBurgers + 1;
		}
		else
			maxBurgers = currBurgers - 1;
	}

	cout << ans << "\n";

	return 0;
}