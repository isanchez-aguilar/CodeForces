/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 246D - Colorful Graph
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> colours(n);
	vector<bool> availableColour(100001);

	for (int i = 0; i < n; ++i)
	{
		cin >> colours[i];
		--colours[i];
		availableColour[colours[i]] = true;
	}

	vector< set<int> > score(100001);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		
		--u, --v;
		int cu = colours[u];
		int cv = colours[v];

		if (cu != cv)
		{
			score[cu].insert(cv);
			score[cv].insert(cu);
		}

	}

	int maxScore = -1;
	int maxColour = -1;

	for (int i = 0; i < 100001; ++i)
	{
		if (availableColour[i] and maxScore < int(score[i].size()))
		{
			maxColour = i;
			maxScore = score[i].size();
		}
	}

	cout << maxColour + 1 << "\n";

	return 0;
}