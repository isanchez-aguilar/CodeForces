/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1077E - Thematic Contests
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, int> freq;
	
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		++freq[val];
	}

	vector<int> sortedFreq;
	sortedFreq.reserve(freq.size());

	for (const pair<int, int>& p : freq)
		sortedFreq.push_back(p.second);

	int ans = 0;
	sort(begin(sortedFreq), end(sortedFreq));

	for (int i = 1; i <= sortedFreq.back(); ++i)
	{
		int currentVal = i;
		int currentProblems = i;

		for (int j = (int)sortedFreq.size() - 1; j > 0 and currentVal % 2 == 0; --j)
		{
			currentVal /= 2;

			if (sortedFreq[j - 1] < currentVal)
				break;

			currentProblems += currentVal;							
		}

		ans = max(ans, currentProblems);
	}

	cout << ans << "\n";

	return 0;
}