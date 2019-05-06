/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1077D - Cutting Out
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int maxFreq = -1;
	map<int, int> freq;

	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;

		++freq[val];
		maxFreq = max(maxFreq, freq[val]);
	}

	vector< pair<int, int> > sortedFreq;
	sortedFreq.reserve((freq.size()));

	for (const pair<int, int>& p : freq)
		sortedFreq.push_back(make_pair(p.second, p.first));

	sort(begin(sortedFreq), end(sortedFreq), greater< pair<int, int> >());

	int left = 1;
	vector<int> ans(k);
	int right = maxFreq;
	vector<int> auxAns(k);

	while (left <= right)
	{
		const int middle = (left + right) / 2;

		int currentCorrect = 0;


		for (int i = 0; currentCorrect < k and i < (int)sortedFreq.size(); ++i)
		{
			if (sortedFreq[i].first < middle)
			{
				currentCorrect = -1;
				break;
			}

			for (int j = 0; j < sortedFreq[i].first / middle and currentCorrect < k; ++j)
			{
				auxAns[currentCorrect] = sortedFreq[i].second;
				++currentCorrect;
			}
		}

		if (currentCorrect < k)
			right = middle - 1;
		else
		{
			ans = auxAns;
			left = middle + 1;
		}
	}


	for (int i = 0; i < k; ++i)
		cout << (i == 0?"":" ") << ans[i];

	return 0;
}