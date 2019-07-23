/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1154G - Minimum Possible LCM
*/
#include <bits/stdc++.h>

#define MAX_N 10000001

using namespace std;
using Long = long long;

vector<int> nums;
vector<int> primes;
vector<int> divisors(MAX_N);
pair<int, int> minCommon[MAX_N];
vector< pair<int, int> > primeDivisors;

inline void createSieve()
{
	divisors[0] = divisors[1] = 0;

	for (int i = 2; i < MAX_N; ++i)
	{
		if (divisors[i] == 0)
		{
			divisors[i] = i;
			primes.push_back(i);
		}

		for (int j = 0; j < primes.size() and primes[j] <= divisors[i] and i * primes[j] < MAX_N; ++j)
			divisors[i * primes[j]] = primes[j];
	}

	return;
}

inline void addMinCommon(int div, int index)
{
	if (minCommon[div].first == -1)
		minCommon[div].first = index;
	else if (minCommon[div].second == -1)
		minCommon[div].second = index;

	return;
}

void generateDivisors(int divIndex, int div, const int& index)
{
	if (divIndex == primeDivisors.size())
		addMinCommon(div, index);
	else
	{
		int currPow = 1;

		for (int i = 0; i <= primeDivisors[divIndex].second; ++i)
		{
			generateDivisors(divIndex + 1, div * currPow, index);
			currPow *= primeDivisors[divIndex].first;
		}
	}

	return;
}

inline void addDivisors(const int& index)
{
	int v = nums[index];
	primeDivisors.clear();

	while (v > 1)
	{
		int div = divisors[v];

		if (not primeDivisors.empty() and primeDivisors.back().first == div)
			++primeDivisors.back().second;
		else
			primeDivisors.push_back(make_pair(div, 1));

		v /= div;
	}

	generateDivisors(0, 1, index);

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	nums = vector<int>(n);

	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	createSieve();
	fill(minCommon, minCommon + MAX_N, make_pair(-1, -1));

	vector< pair<int, int> > vals(n);

	for (int i = 0; i < n; ++i)
		vals[i] = make_pair(nums[i], i);

	sort(begin(vals), end(vals));

	for (int i = 0; i < n; ++i)
	{
		if (i > 1 and vals[i].first == vals[i - 2].first)
			continue;

		addDivisors(vals[i].second);
	}	

	int ansI, ansJ;
	Long minLCM = LLONG_MAX;

	for (int i = 1; i < MAX_N; ++i)
	{	
		pair<int, int> common = minCommon[i];

		if (minCommon[i].second != -1)
		{
			Long currLCM = Long(nums[common.first]) * Long(nums[common.second]) / Long(i);

			if (currLCM < minLCM)
			{
				minLCM = currLCM;
				ansI = min(common.first, common.second);
				ansJ = max(common.first, common.second);
			}
		}
	}

	cout << ansI + 1 << " " << ansJ + 1 << "\n";

	return 0;
}