/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 441C - Valera and Tubes
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector< pair<int, int> > path;
	path.reserve(n * m);

	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < m; ++j)
				path.emplace_back(i + 1, j + 1);
		}
		else
		{
			for (int j = m - 1; j >= 0; --j)
				path.emplace_back(i + 1, j + 1);
		}
	}

	int currIndex = 0;

	for (int i = 0; i < k - 1; ++i)
	{
		cout << "2 " << path[currIndex].first << " " << path[currIndex].second;
		cout << " " << path[currIndex + 1].first << " " << path[currIndex + 1].second << "\n";
		currIndex += 2;
	}

	cout << n * m - currIndex;

	while (currIndex < n * m)
	{
		cout << " " << path[currIndex].first << " " << path[currIndex].second;
		++currIndex;
	}

	cout << "\n";

	return 0;
}
