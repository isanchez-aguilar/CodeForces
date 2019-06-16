/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1108F - MST Unification
*/
#include <bits/stdc++.h>

using namespace std;

class Edge {
public:
	int u, v, w;

	Edge(){}

	Edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){}

	inline bool operator<(const Edge& e)
	{
		return w < e.w;
	}
};

class DisjointSet {
public:
	int size;
	vector<int> rank;
	vector<int> parent;

	DisjointSet(int n):size(n), parent(n), rank(n, 1)
	{
		iota(begin(parent), end(parent), 0);
	}

	int getParent(int u)
	{
		if (parent[u] == u)
			return u;

		return parent[u] = getParent(parent[u]);
	}

	bool areConnected(int u, int v)
	{
		return getParent(u) == getParent(v);
	}

	bool match(int u, int v)
	{
		if (not areConnected(u, v))
		{
			int parentU = getParent(u);
			int parentV = getParent(v);

			if (rank[u] < rank[v])
			{
				parent[parentU] = parentV;
				++rank[parentV];
			}
			else
			{
				parent[parentV] = parentU;
				++rank[parentU];
			}

			return true;
		}

		return false;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<Edge> graph(m);

	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[i] = Edge(u - 1, v - 1, w);
	}

	int ans = 0;
	DisjointSet tree(n);
	sort(begin(graph), end(graph));

	for (int i = 0; i < m; ++i)
	{
		int j = i;

		while (j < m and graph[j].w == graph[i].w)
			++j;

		int currentAns = j - i;

		for (int k = i; k < j; ++k)
		{
			if (tree.areConnected(graph[k].u, graph[k].v))
				--currentAns;
		}

		for (int k = i; k < j; ++k)
		{
			if (tree.match(graph[k].u, graph[k].v))
				--currentAns;
		}

		i = j - 1;
		ans += currentAns;
	}

	cout << ans << "\n";

	return 0;
}