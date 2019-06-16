/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1176B - Merge it!
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		int n;
		cin >> n;

		vector<int> modFreq(3);
		
		for (int i = 0; i < n; ++i)
		{
			Long val;
			cin >> val;
			++modFreq[val % 3];
		}

		int ans = modFreq[0];

		int minFreq = min(modFreq[1], modFreq[2]);

		ans += minFreq;
		modFreq[1] -= minFreq;
		modFreq[2] -= minFreq;
		ans += (modFreq[1] + modFreq[2]) / 3;

		cout << ans << "\n";
	}

	return 0;
}