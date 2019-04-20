/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 450B - Jzzhu and Sequences
*/
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Number x, y, n;
	cin >> x >> y >> n;

	Number ans[6] = {x, y, y - x, -x, - y, x - y};

	cout << ((ans[(n - 1) % 6] % MOD) + MOD) % MOD  << "\n";

	return 0;
}