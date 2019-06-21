/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1133F1 - Spanning Tree with Maximum Degree
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> deg(n);
	vector< vector<int> > graph(n);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		--u, --v;
		
		++deg[u];
		++deg[v];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	queue<int> nodes;
	vector<bool> visited(n);
	vector< pair<int, int> > ans;
	int root = distance(begin(deg), max_element(begin(deg), end(deg)));

	nodes.push(root);
	visited[root] = true;

	while (not nodes.empty())
	{
		int u = nodes.front();
		nodes.pop();

		for (int v : graph[u])
		{
			if (not visited[v])
			{
				nodes.push(v);
				visited[v] = true;
				ans.push_back(make_pair(u + 1, v + 1));
			}
		}
	}

	for (const pair<int, int>& e : ans)
		cout << e.first << " " << e.second << "\n";

	return 0;
}