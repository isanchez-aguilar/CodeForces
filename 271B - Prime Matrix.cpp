/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 271B - Prime Matrix
*/
#include <bits/stdc++.h>

#define MAX_VALUE 1000001

using namespace std;
using Number = long long;

vector<Number> primes;
vector<bool> isNotPrime(MAX_VALUE);

inline void sieve()
{
	isNotPrime[0] = true;
	isNotPrime[1] = true;

	for (int i = 4; i < MAX_VALUE; i += 2)
		isNotPrime[i] = true;

	primes.push_back(2);
	
	for (Number i = 3; i < MAX_VALUE; i += 2)
	{
		if (not isNotPrime[i])
		{
			primes.push_back(i);

			for (Number j = i * i; j < MAX_VALUE; j += i)
				isNotPrime[j] = true;
		}
	}


	return;
}

inline bool isPrime(Number n)
{
	bool testPrime = true;

	if (n < MAX_VALUE)
		testPrime = not isNotPrime[n];
	else
	{
		Number sqrtN = (Number)sqrt(n);

		for (int i = 0; i < (int)primes.size() and primes[i] <= sqrtN; ++i)
		{
			if (n % primes[i] == 0)
			{
				testPrime = false;
				break;
			}
		}
	}

	return testPrime;
}

inline Number findNextPrime(Number n)
{
	return *lower_bound(begin(primes), end(primes), n);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	sieve();

	int mat[n][m];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> mat[i][j];
	}

	Number rowSum[n];
	Number columnSum[m];

	memset(columnSum, 0, sizeof columnSum);

	for (int i = 0; i < n; ++i)
	{
		rowSum[i] = 0;

		for (int j = 0; j < m; ++j)
		{
			Number offsetPrime = 0;

			if (not isPrime(mat[i][j]))
			{
				Number nextPrime = findNextPrime(mat[i][j]);
				offsetPrime = nextPrime - mat[i][j];
			}

			rowSum[i] += offsetPrime;
			columnSum[j] += offsetPrime;
		}
	}

	Number minRows = *min_element(rowSum, rowSum + n);
	Number minColumns = *min_element(columnSum, columnSum + m);

	cout << min(minRows, minColumns) << "\n";

	return 0;
}