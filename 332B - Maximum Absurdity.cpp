/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 332B - Maximum Absurdity
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<Long> vals(n);

	for (int i = 0; i < n; ++i)
		cin >> vals[i];

	vector< pair<Long, int> > memo(n, {-1, -1});

	Long currSum = accumulate(end(vals) - k, end(vals), 0);
	memo[n - k] = {currSum, n - k};

	for (int i = n - k - 1; i >= 0; --i)
	{
		currSum -= vals[i + k];
		currSum += vals[i];
		memo[i] = max(memo[i + 1], {currSum, i});
		
		if (memo[i + 1].first == currSum)
			memo[i].second = i;
	}

	currSum = accumulate(begin(vals), begin(vals) + k, 0);
	
	pair<int, int> ans(0, memo[k].second);
	Long maxSum = currSum + memo[k].first;

	for (int i = 1; i <= n - 2 * k; ++i)
	{
		currSum -= vals[i - 1];
		currSum += vals[i + k - 1];

		if (maxSum < currSum + memo[i + k].first)
		{
			ans = {i, memo[i + k].second};
			maxSum = currSum + memo[i + k].first;
		}
	}

	cout << ans.first + 1 << " " << ans.second + 1 << "\n";

	return 0;
}