#include <bits/stdc++.h>

#define MAX 10007 

using namespace std;
using Number = unsigned long long;

bool isNotPrime[MAX + 1];

void sieve()
{
	isNotPrime[0] = isNotPrime[1] = true;

	for (Number i = 4; i <= MAX; i += 2)
		isNotPrime[i] = true;

	for (Number i = 3; i <= MAX; i += 2)
	{
		if (not isNotPrime[i])
		{
			for (Number j = i * i; j <= MAX; ++j)
				isNotPrime[j] = true;
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	sieve();

	for (int t = 1; t <= testCases; ++t)
	{
		Number n;
		cin >> n;

		cout << "Case #" << t << ": ";

		if (n == 1)
			cout << "1\n";
		else if (n == 2)
			cout << "0\n";
		else
		{
			if (isNotPrime[n])
				cout << ((n - 1) % n * (n - 1) % n) % n << "\n";
			else
				cout << "1\n";

		}
	}

	return 0;
}