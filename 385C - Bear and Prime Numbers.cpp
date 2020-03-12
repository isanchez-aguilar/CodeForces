/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 385C - Bear and Prime Numbers
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

const int maxVal = 10000000;

vector<Long> primes;
Long smallestPrimeFactor[maxVal + 1];

/*
** Algorithm: Linear Sieve of Eratostenes.
** Complexity: O(n)
*/
inline void createSieve()
{
	smallestPrimeFactor[1] = 1;

	for (Long i = 2; i <= maxVal; ++i)
	{
		if (smallestPrimeFactor[i] == 0)
		{
			smallestPrimeFactor[i] = i;
			primes.push_back(i);
		}

		for (Long j = 0; j < int(primes.size()) and primes[j] <= smallestPrimeFactor[i] and i * primes[j] <= maxVal; ++j)
			smallestPrimeFactor[i * primes[j]] = primes[j];
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	createSieve();

	int n;
	cin >> n;

	vector<Long> a(n);
	vector<Long> accum(maxVal + 1);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(begin(a), end(a));

	int i = 0;

	while (i < n)
	{
		int j = i;
		int amount = 0;

		while (j < n and a[i] == a[j])
			++j, ++amount;

		i = j - 1;

		while (a[i] > 1)
		{
			Long d = smallestPrimeFactor[a[i]];

			while (a[i] % d == 0)
				a[i] /= d;

			accum[d] += amount;
		}

		++i;
	}

	for (int i = 1; i <= maxVal; ++i)
		accum[i] += accum[i - 1];

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int l, r;
		cin >> l >> r;

		l = min(l, maxVal);
		r = min(r, maxVal);

		Long ans = accum[r] - accum[l - 1];

		cout << ans << "\n";
	}

	return 0;
}