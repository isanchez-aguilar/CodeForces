/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1183G - Candy Box (hard version)
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	while (q--)
	{
		int n;
		cin >> n;

		vector<int> freq(n);
		vector<int> goodFreq(n);

		for (int i = 0; i < n; ++i)
		{
			int a, f;
			cin >> a >> f;

			--a;
			++freq[a];
			
			if (f == 1)
				++goodFreq[a];
		}

		vector<int> candiesFreq[n + 1];

		for (int i = 0; i < n; ++i)
			candiesFreq[freq[i]].push_back(goodFreq[i]);

		int ansGood = 0;
		int ansCandies = 0;
		multiset< int, greater<int> > goodCandies;

		for (int i = n; i > 0; --i)
		{
			for (int freqGood : candiesFreq[i])
				goodCandies.insert(freqGood);

			if (not goodCandies.empty())
			{
				ansCandies += i;
				ansGood += min(i, *begin(goodCandies));
				goodCandies.erase(begin(goodCandies));
			}
		}

		cout << ansCandies << " " << ansGood << "\n";
	}

	return 0;
}