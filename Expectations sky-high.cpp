#include <bits/stdc++.h>

#define MOD 1000000007ll

using namespace std;
using Number = long long;

Number p = 0;
Number q = 0;
vector< vector<int> > graph;
vector<Number> sizeOfSubTree;
vector<Number> sumOfDistances;

void dfs(int currentNode, int parent)
{
	sizeOfSubTree[currentNode] = 1;

	for (int child : graph[currentNode])
	{
		if (child != parent)
		{
			dfs(child, currentNode);

			p += (sumOfDistances[currentNode] * sizeOfSubTree[child]) % MOD;
			p += sizeOfSubTree[currentNode] * ((sizeOfSubTree[child] + sumOfDistances[child]));

			sumOfDistances[currentNode] += sumOfDistances[child] + sizeOfSubTree[child];
			sizeOfSubTree[currentNode] += sizeOfSubTree[child];
			
			p %= MOD;
			sizeOfSubTree[currentNode] %= MOD;
			sumOfDistances[currentNode] %= MOD;
		}
	}

	return;
}

inline Number binomialCoefficient(Number n, Number k)
{
	Number C[k + 1];
	memset(C, 0, sizeof(C));

	C[0] = 1;

	for (Number i = 1; i <= n; ++i)
	{
		for (Number j = min(i, k); j > 0; --j)
			C[j] = C[j] + C[j-1];
	}

	return C[k];
}

inline Number modularInverse(Number a, Number m)
{
	if (m == 1)
		return 0;

	Number y = 0;
	Number x = 1;
	Number m0 = m;

	while (a > 1)
	{
		Number q = a / m;
		Number t = m;

		m = a % m;
		a = t;
		t = y;

		y = x - q * y;
		x = t;
	}

	if (x < 0)
		x += m0;

	return x;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	graph = vector< vector<int> >(n + 1);
	sizeOfSubTree = vector<Number>(n + 1);
	sumOfDistances = vector<Number>(n + 1);

	for (int i = 0; i < n - 1; ++i)
	{
		int u;
		int v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 1);

	q = binomialCoefficient(n, 2ll) + n;

	cout << (p * (modularInverse(q, MOD)) % MOD) << "\n";

	return 0;
}