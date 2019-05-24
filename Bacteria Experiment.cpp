#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int farthestNode;
vector<bool> visited;
Number longestPath = 0;
vector< vector<int> > adj;

void dfs(int node, int currentLengthPath)
{
	++currentLengthPath;
	visited[node] = true;

	for (int i = 0; i < adj[node].size(); ++i)
	{
		const int& neighbor = adj[node][i];

		if (not visited[neighbor])
		{
			if (longestPath <= currentLengthPath)
			{
				longestPath = currentLengthPath;
				farthestNode = neighbor;
			}

			dfs(neighbor, currentLengthPath);
		}
	}
}

inline Number getDiameterOfGraph()
{
	int nodes = adj.size();
	longestPath = LLONG_MIN;
	visited = vector<bool>(nodes, false);

	dfs(0, 0);

	fill(visited.begin(), visited.end(), false);
	
	dfs(farthestNode, 0);
	
	return longestPath;
}

int main(void) 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nodes;
	cin >> nodes;

	adj = vector< vector<int> >(nodes);

	for (int i = 0; i < nodes - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		--u, --v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (nodes <= 2)
		cout << "0\n";
	else
	{
		Number diamater = getDiameterOfGraph();
		Number ans = (Number)ceil(log2((double)diamater));

		cout << ans << "\n";
	}
	
	return 0;
}