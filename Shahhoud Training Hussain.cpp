#include <bits/stdc++.h>

using namespace std;
using Number = unsigned long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		Number k, p, n;
		cin >> k >> p >> n;

		Number minSolved = min(k, p);

		cout << (k - minSolved) * n << "\n";
	}

	return 0;
}