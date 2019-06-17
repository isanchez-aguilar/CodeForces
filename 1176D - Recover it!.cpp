/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1176D - Recover it!
*/
#include <bits/stdc++.h>

#define MAX_N 2750132

using namespace std;
using Long = long long;

Long factor[MAX_N];
vector<Long> primes;
bool isNotPrime[MAX_N];

inline void createSieve()
{
	primes.push_back(2);

	for (int i = 4; i < MAX_N; i += 2)
		isNotPrime[i] = true;
	
	for (Long p = 3; p < MAX_N; p += 2)
	{
		if (not isNotPrime[p])
		{	
			factor[p] = p;
			primes.push_back(p);
		}

		for (int j = 0; j < primes.size() and p * primes[j] < MAX_N and primes[j] <= factor[p]; ++j)
		{
			factor[p * primes[j]] = primes[j];
			isNotPrime[p * primes[j]] = true;
		}
	}

	return;
}

inline Long getMaxDivisor(Long n)
{
	Long maxDivisor = -1;
	const Long sqrtN = Long(sqrt(n));

	for (int i = 0; i < primes.size() and primes[i] <= sqrtN; ++i)
	{
		if (n % primes[i] == 0)
		{
			maxDivisor = max(n / primes[i], primes[i]);
			break;
		}
	}

	return maxDivisor;
}

inline void deleteFromMap(map<Long, int>& m, Long val)
{
	--m[val];

	if (m[val] == 0)
		m.erase(val);

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<Long, int> vals;

	for (int i = 0; i < 2 * n; ++i)
	{
		Long val;
		cin >> val;
		++vals[val];
	}

	vector<Long> ans;

	createSieve();
	ans.reserve(n);
	
	while(not vals.empty())
	{
		map<Long, int>::iterator largest = --end(vals);
		
		Long val = largest->first;
		deleteFromMap(vals, val);

		if (isNotPrime[val])
		{
			ans.push_back(val);
			Long maxDivisor = getMaxDivisor(val);
			deleteFromMap(vals, maxDivisor);
		}
		else
		{
			vector<Long>::iterator j = lower_bound(begin(primes), end(primes), val);
			Long num = distance(begin(primes), j) + 1;
			ans.push_back(num);
			
			deleteFromMap(vals, num);
		}
	}

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << (i == ans.size() - 1?"\n":" ");

	return 0;
}