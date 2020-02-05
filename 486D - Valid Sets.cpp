/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 486D - Valid Sets
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

const Long MOD = 1000000007ll;

int d;
vector<int> vals;
vector<bool> visited;
vector< vector<int> > graph;

Long dfs(int u, int root)
{
	Long ans = 1;
	visited[u] = true;

	for (int v : graph[u])
	{
		if (not visited[v] and ((vals[v] > vals[root] and vals[root] + d >= vals[v]) or (vals[v] == vals[root] and v > root)))
		{
			ans *= dfs(v, root) + 1ll;
			ans %= MOD;
		}
	}

	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> d >> n;

	vals.resize(n);
	graph.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; ++i)
		cin >>  vals[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		--u, --v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}

	Long ans = 0;

	for (int i = 0; i < n; ++i)
	{
		fill(begin(visited), end(visited), false);
		ans += dfs(i, i);
		ans %= MOD;
	}

	cout << ans << "\n";

	return 0;
}