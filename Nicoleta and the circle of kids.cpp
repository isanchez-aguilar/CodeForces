#include <bits/stdc++.h>

using namespace std;
using Number = unsigned long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Number n, k;
	cin >> n >> k;

	const Number gcd = __gcd(n, k);

	Number totalSum = (n - gcd) * k;

	if (gcd != 1)
		totalSum += (k - 1) * (gcd - 1);

	cout << totalSum << "\n";

	return 0;
}