/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1118F - Tree Cutting (Easy Version)
*/
#include <bits/stdc++.h>

using namespace std;

int ans;
int totalRed;
int totalBlue;
vector<int> colours;
vector< vector<int> > graph;

pair<int, int> dfs(const int& u, const int& parent)
{
	int red = colours[u] == 1;
	int blue = colours[u] == 2;

	for (int v : graph[u])
	{
		if (v != parent)
		{
			pair<int, int> freq = dfs(v, u);

			if (freq.first == totalRed and freq.second == 0)
				++ans;
			else if(freq.first == 0 and freq.second == totalBlue)
				++ans;

			red += freq.first;
			blue += freq.second;
		}
	}

	return make_pair(red, blue);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	totalRed = 0;
	totalBlue = 0;
	colours.resize(n);
	graph = vector< vector<int> >(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> colours[i];

		if (colours[i] == 1)
			++totalRed;
		else if (colours[i] == 2)
			++totalBlue;
	}

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	ans = 0;

	dfs(0, -1);

	cout << ans << "\n";

	return 0;
}