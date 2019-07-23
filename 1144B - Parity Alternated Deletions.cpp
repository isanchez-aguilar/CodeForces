/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1144B - Parity Alternated Deletions
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<Long> odds;
	vector<Long> evens;

	for (int i = 0; i < n; ++i)
	{
		Long val;
		cin >> val;

		if (val % 2 == 0)
			evens.push_back(val);
		else
			odds.push_back(val);
	}

	sort(begin(odds), end(odds));
	sort(begin(evens), end(evens));

	int minSize = min(odds.size(), evens.size());

	odds.resize(int(odds.size()) - minSize - (odds.size() > minSize));
	evens.resize(int(evens.size()) - minSize - (evens.size() > minSize));

	cout << accumulate(begin(evens), end(evens), 0) + accumulate(begin(odds), end(odds), 0) << "\n";

	return 0;
}