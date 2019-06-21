/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1133F2 - Spanning Tree with One Fixed Degree
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> parent;
int amountComponents;
vector<int> component;
vector< vector<int> > graph;
vector< pair<int, int> > ans;

inline void bfs(int root, int ignoredNode)
{
	queue<int> nodes;
	nodes.push(root);
	component[root] = amountComponents;

	while (not nodes.empty())
	{
		int u = nodes.front();
		nodes.pop();

		if (parent[u] != -1)
				ans.push_back(make_pair(parent[u], u));

		for (int v : graph[u])
		{
			if (v != ignoredNode and component[v] == -1)
			{
				nodes.push(v);
				parent[v] = u;
				component[v] = amountComponents;
			}
		}
	}

	++amountComponents;

	return;
}

inline bool byComponent(const int& u, const int& v)
{
	return component[u] < component[v];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int d;
	cin >> n >> m >> d;

	parent = vector<int>(n, -1);
	component = vector<int>(n, -1);
	graph = vector< vector<int> >(n);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	amountComponents = 0;

	for (int i  = 1; i < n; ++i)
	{
		if (component[i] == -1)
			bfs(i, 0);
	}

	if (d < amountComponents or graph[0].size() < d)
		cout << "NO\n";
	else
	{
		sort(begin(graph[0]), end(graph[0]), byComponent);

		d -= amountComponents;

		for (int i = 0; i < (int)graph[0].size(); ++i)
		{
			if (i == 0 or component[graph[0][i]] != component[graph[0][i - 1]])
				ans.push_back(make_pair(0, graph[0][i]));
		}

		for (int i = 1; i < (int)graph[0].size() and d > 0; ++i)
		{
			if (component[graph[0][i]] == component[graph[0][i - 1]])
			{
				--d;
				ans.push_back(make_pair(0, graph[0][i]));
			}
		}

		graph = vector< vector<int> >(n);

		for (const pair<int, int>& e : ans)
		{
			int u = e.first;
			int v = e.second;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		component = vector<int>(n, -1);
		parent = vector<int>(n, -1);
		amountComponents = 0;
		ans.clear();

		cout << "YES\n";
		bfs(0, -1);

		for (const pair<int, int>& e : ans)
			cout << e.first + 1 << " " << e.second + 1 << "\n";
	}
	return 0;
}