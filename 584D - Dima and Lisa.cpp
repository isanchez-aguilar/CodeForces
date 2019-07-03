/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 584D - Dima and Lisa
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;

long long n;
long long p;
long long a;
long long b;
long long c;
bool isNotPrime[MAX];
long long factor[MAX];
vector<long long> prime(1, 2);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 4; i < MAX; i += 2)
		isNotPrime[i] = true;
	
	for (p = 3; p < MAX; p += 2)
	{
		if (not isNotPrime[p])
		{	
			factor[p] = p;
			prime.push_back(p);
		}

		for (int j = 0; j < prime.size() and p * prime[j] < MAX and prime[j] <= factor[p]; ++j)
		{
			factor[p * prime[j]] = prime[j];
			isNotPrime[p * prime[j]] = true;
		}
	}

	cin >> n;

	if (n == 3)
		cout << "1\n3";
	else if (n <= prime.back() and not isNotPrime[n])
		cout << "1\n" << n << "\n";
	else
	{
		a = 3;
		n -= 3;

		for (int i = 0; 2 * prime[i] <= n; ++i)
		{
			b = prime[i];
			c = n - prime[i];

			if (b == c)
				break;

			bool found = true;

			for (int j = 0; j < prime.size() and prime[j] * prime[j] <= c; ++j)
			{
				if (c % prime[j] == 0)
				{
					found = false;
					break;
				}
			}

			if (found)
				break;
		}

		cout << "3\n";
		cout << a << " " << b  << " " << c << "\n";
	}

	return 0;
}