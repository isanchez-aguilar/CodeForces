/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1102B - Array K-Coloring
*/
#include <bits/stdc++.h>

using namespace std;
using Long  = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int maxFreq = 0;
	map<int, int> freq;
	map<int, int> indexNumber;
	vector< vector<int> > posVal;

	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;

		int index = 0;

		if (indexNumber.count(val) == 0)
		{
			index = posVal.size();
			indexNumber[val] = index;
			posVal.push_back(vector<int>(0));
		}
		
		index = indexNumber[val];

		++freq[val];
		posVal[index].push_back(i);
		maxFreq = max(maxFreq, freq[val]);
	}
	if (k < maxFreq)
		cout << "NO\n";
	else
	{
		vector<int> ans(n);
		int currentColour = 0;

		for (map<int, int>::iterator i = begin(freq); i != end(freq); ++i)
		{
			const int val = i->first;
			const int index = indexNumber[val];

			for (int p : posVal[index])
			{
				ans[p] = currentColour;
				currentColour = (currentColour + 1) % k;
			}
		}

		cout << "YES\n" << ans[0] + 1;

		for (int i = 1; i < n; ++i)
			cout << " " << ans[i] + 1;

		cout << "\n";
	}
	return 0;
}