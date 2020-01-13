/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 369C - Valera and Elections
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using Long = long long;

vector<int> solution;
vector< vector<int> > graph;
vector<bool> visited(100001);
vector<bool> problemVertices(100001);

int dfs(int u)
{
	int ansNode = 0;
	visited[u] = true;
	vector<int> problem;

	problem.reserve(graph[u].size());

	for (int v : graph[u])
	{
		if (not visited[v])
		{
			int currAns = dfs(v);

			if (currAns > 0)
				ansNode += currAns;

			if (problemVertices[v])
				problem.emplace_back(v);
		}
	}

	if (ansNode == 0 and problemVertices[u])
	{
		++ansNode;
		solution.emplace_back(u + 1);
	}

	return ansNode;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int vertices;
	cin >> vertices;

	const int edges = vertices - 1;

	graph = vector< vector<int> >(vertices);

	for (int i = 0; i < edges; ++i)
	{
		int u, v, t;
		cin >> u >> v >> t;

		--u, --v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);

		if (t == 2)
		{
			problemVertices[u] = true;
			problemVertices[v] = true;
		}
	}

	solution.reserve(vertices);

	dfs(0);

	cout << solution.size() << "\n";

	for (int u : solution)
		cout << u << " ";

	cout << "\n";

	return 0;
}
