/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 466C - Number of Ways
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	Long sum = 0;
	vector<Long> a(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	Long ans = 0;
	if (sum % 3ll == 0)
	{
		Long div = sum / 3ll;

		Long currSum = 0;
		map<Long, Long> freqPrefixSum;

		vector<Long> memo(n);

		for (int i = 0; i < n; ++i)
		{
			currSum += a[i];

			if (freqPrefixSum.count(currSum) == 0)
				freqPrefixSum[currSum] = 0;

			if (currSum == 2 * div and freqPrefixSum.count(currSum - div))
				memo[i] += freqPrefixSum[currSum - div];
			
			++freqPrefixSum[currSum];
		}

		currSum = 0;
		
		for (int i =  n - 1; i >= 0; --i)
		{
			currSum += a[i];

			if (currSum == div and i > 0)
				ans += memo[i - 1];
		}
	}

	cout << ans << "\n";

	return 0;
}

