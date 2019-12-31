/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1269B - Modulo Equality
*/
#include <bits/stdc++.h>

using namespace std;
using Long =  long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	Long m;
	cin >> n >> m;

	Long val;
	map<Long, int> freqA;

	for (int i = 0; i < n; ++i)
	{
		cin >> val;
		++freqA[val];
	}

	map<Long, int> freqB;

	for (int j = 0; j < n; ++j)
	{
		cin >> val;
		++freqB[val];
	}

	Long ans = 0;

	if (freqA != freqB)
	{
		ans = LLONG_MAX;
		vector< pair<int, int> > sortedFreqA;
		vector< pair<int, int> > sortedFreqB;

		sortedFreqA.reserve(freqA.size());
		sortedFreqA.reserve(freqB.size());

		for (auto& p : freqA)
			sortedFreqA.emplace_back(p.second, p.first);
		
		for (auto& p : freqB)
			sortedFreqB.emplace_back(p.second, p.first);

		sort(begin(sortedFreqA), end(sortedFreqA), greater< pair<int, Long> >());
		sort(begin(sortedFreqB), end(sortedFreqB), greater< pair<int, Long> >());

		val = sortedFreqA[0].second;

		for (int i = 0; i < int(sortedFreqB.size()) and sortedFreqB[i].first == sortedFreqA[0].first; ++i)
		{
			Long x = sortedFreqB[i].second - val;

			if (x < 0)
				x = sortedFreqB[i].second + m - val;

			//cerr << x << ":" << val << "," << sortedFreqB[i].second << endl;

			map<Long, int> auxF = freqB;

			for (auto& p : sortedFreqA)
			{
				Long newVal = (p.second + x) % m;
				auxF[newVal] -= p.first;
				//cerr << newVal << "," << p.second << "," << auxF[newVal] << endl;
			}

			bool isGood = true;

			for (auto& p : auxF)
			{
				//cerr << p.first << "<>" << p.second << endl;
				if (p.second != 0)
				{
					isGood = false;
					break;
				}
			}

			if (isGood)
				ans = min(ans, x);
		}
	}

	cout << ans << "\n";

	return 0;
}