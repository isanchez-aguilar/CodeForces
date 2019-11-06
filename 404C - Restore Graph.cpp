/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 404C - Restore Graph
*/
#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > adj;

int dfs(int u, int parent)
{
	int visited = 1;

	for (int v : adj[u])
	{
		if (v != parent)
			visited += dfs(v, u);
	}
	
	return visited;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int nodes, maxDegree;
	cin >> nodes >> maxDegree;

	int edges = 0;
	bool possible = true;
	vector< vector<int> > ans(nodes);
	vector< pair<int, int> > distNodes(nodes);

	adj = ans;

	for (int i = 0; i < nodes; ++i)
	{
		distNodes[i].second = i;
		cin >> distNodes[i].first;
	}

	sort(begin(distNodes), end(distNodes));

	int i = 0;
	vector<int> degree(nodes);
	queue<int> prevNodes;
	int prevDist = 0;

	while (i < nodes and distNodes[i].first == 0)
	{
		prevNodes.push(distNodes[i].second);
		++i;
	}

	while (i < nodes and possible)
	{
		queue<int> newPrev;
		int currDist = distNodes[i].first;

		while (i < nodes and distNodes[i].first == currDist)
		{
			int u = distNodes[i].second;

			if (prevNodes.empty() or prevDist < currDist - 1)
			{
				possible = false;
				break;
			}

			int v = prevNodes.front();
			prevNodes.pop();

			++degree[u];
			++degree[v];
			ans[v].push_back(u);
			adj[v].push_back(u);
			adj[u].push_back(v);

			if (degree[v] + 1 <= maxDegree)
				prevNodes.push(v);

			++i;
			++edges;
			
			if (degree[u] + 1 <= maxDegree)
				newPrev.push(u);
		}

		prevDist = currDist;
		prevNodes = newPrev;
	}

	if (possible)
	{
		for (int i = 0; i < nodes; ++i)
		{
			if (degree[i] > maxDegree or int(ans[i].size()) > maxDegree)
				possible = false;
		}


		if (dfs(0, 0) < nodes)
			possible = false;
	}

	if (not possible)
		edges = -1;
	
	cout << edges << "\n";

	if (possible)
	{
		for (int i = 0; i < nodes; ++i)
		{
			for (int u : ans[i])
				cout << i + 1 << " " << u + 1 << "\n";
		}
	}

	return 0;
}