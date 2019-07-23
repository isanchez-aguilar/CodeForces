/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1144F - Graph Without Long Directed Paths
*/
#include <bits/stdc++.h>

#define UNCOLORED -1

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector< vector<int> > graph(n);
	vector< pair<int, int> > edges(m);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		--u, --v;
		edges[i] = make_pair(u, v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<int> remaining;
	vector<int> colour(n, UNCOLORED);

	remaining.push(0);
	colour[0] = 1;

	while (not remaining.empty())
	{
		int u = remaining.front();
		remaining.pop();

		for (int v : graph[u])
		{
			if (colour[v] == -1)
			{
				remaining.push(v);
				colour[v] = not colour[u];
			}
		}
	}
	
	bool isBipartite = true;

	for (int i = 0; i < m; ++i)
	{
		const pair<int, int> e = edges[i];

		if (colour[e.first] == colour[e.second])
		{
			isBipartite = false;
			break;
		}
	}

	if (isBipartite)
	{
		cout << "YES\n";

		for (int i = 0; i < m; ++i)
			cout << colour[edges[i].first];

		cout << "\n";
	}
	else
		cout << "NO\n";

	return 0;
}