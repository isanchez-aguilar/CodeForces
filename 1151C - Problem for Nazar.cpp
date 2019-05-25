/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1151C - Problem for Nazar
*/
#include <bits/stdc++.h>

#define MOD 1000000007ll

using namespace std;
using Long = long long;

inline Long MSBit(Long n)
{
	Long ans = 0;

	while (n / 2ll > 0)
		n /= 2ll, ++ans;

	return ans;
}

inline Long sumEvenPowers(Long n)
{
	return ((1ll << (2 * n)) - 1ll) / 3ll;
}

inline pair<Long, Long> getAmountEvensOdds(Long n)
{
	pair<Long, Long> evenOdds;

	const Long mostSignificantBit = MSBit(n);

	if (mostSignificantBit % 2 == 0)
	{
		evenOdds.first = 2ll * sumEvenPowers(mostSignificantBit / 2);
		evenOdds.second = (n - evenOdds.first) % MOD;
		evenOdds.first %= MOD;
	}
	else
	{
		evenOdds.second  = sumEvenPowers(ceil(double(mostSignificantBit) / 2.0));
		evenOdds.first = (n - evenOdds.second) % MOD;
		evenOdds.second %= MOD;
	}

	return evenOdds;
}

inline Long getSumEvens(Long n)
{
	return (n * (n + 1)) % MOD;
}

inline Long getSumOdds(Long n)
{
	return (n * n) % MOD;
}

inline Long getSum(Long n)
{
	if (n == 0)
		return 0;

	pair<Long, Long> evenOdds = getAmountEvensOdds(n);

	return (getSumEvens(evenOdds.first) + getSumOdds(evenOdds.second)) % MOD;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Long left, right;
	cin >> left >> right;

	cout << (getSum(right) - getSum(left - 1) % MOD + MOD) % MOD << "\n";

	return 0;
}