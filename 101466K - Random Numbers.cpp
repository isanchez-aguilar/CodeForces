/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 101466K - Random Numbers
*/
#include <bits/stdc++.h>

#define SIZE_PRIMES 6
#define MOD 1000000007ull

using namespace std;
using Number = unsigned long long;

const Number primes[SIZE_PRIMES] =  {2ull, 3ull, 5ull, 7ull, 11ull, 13ull};

inline vector<Number> getPowerPrimes(Number val)
{
	vector<Number> powerOfPrimes(SIZE_PRIMES);

	for (int i = 0; i < SIZE_PRIMES and val > 1; ++i)
	{
		Number power = 0;
		while (val % primes[i] == 0)
		{
			val /= primes[i];
			++power;
		}

		powerOfPrimes[i] = power;
	}

	return powerOfPrimes;
}

class Block {
public:
	Number product;
	vector<Number> powerOfPrimes;

	Block():product(1), powerOfPrimes(SIZE_PRIMES){}
	Block(Number val):product(val % MOD), powerOfPrimes(SIZE_PRIMES)
	{
		powerOfPrimes = getPowerPrimes(val);
	}
};

int nodes;
int dfsCounter = -1;
vector<Number> vals;
vector<int> dfsId;
vector<int> dfsNode;
vector<bool> visited;
vector<Block> segmentTree;
vector< vector<int> > tree;
vector< vector<int> > graph;
vector< pair<int, int> > fromTo;

inline void bfs()
{
	queue<int> nodes;

	visited[0] = true;
	nodes.push(0);

	while (not nodes.empty())
	{
		int u = nodes.front();
		nodes.pop();

		for (int v : graph[u])
		{
			if (not visited[v])
			{
				visited[v] = true;
				tree[u].push_back(v);
				nodes.push(v);
			}
		}
	}
}

void dfs(int u)
{
	++dfsCounter;
	visited[u] = true;
	dfsId[u] = dfsCounter;
	dfsNode[dfsCounter] = u;
	fromTo[u] = make_pair(dfsCounter, dfsCounter);

	for (int v : tree[u])
	{
		if (not visited[v])
		{
			dfs(v);
			fromTo[u].first = min(fromTo[u].first, fromTo[v].first);
			fromTo[u].second = max(fromTo[u].second, fromTo[v].second);
		}
	}
}

inline Number countDivisors(const vector<Number>& powerOfPrimes)
{
	Number divisors = 1;

	for (int i = 0; i < SIZE_PRIMES; ++i)
	{
		if (powerOfPrimes[i] > 0)
		{
			divisors *= (powerOfPrimes[i] + 1);
			divisors %= MOD;
		}
	}

	return divisors;
}

void mergeBlocks(Block& a, const Block& b)
{
	for (int i = 0; i < SIZE_PRIMES; ++i)
		a.powerOfPrimes[i] += b.powerOfPrimes[i];

	a.product *= b.product;
	a.product %= MOD;
}

void mergeNodes(const int& index)
{
	const int leftIndex = 2 * index;
	const int rightIndex = 2 * index + 1;

	segmentTree[index].product = 1;
	fill(begin(segmentTree[index].powerOfPrimes), end(segmentTree[index].powerOfPrimes), 0);

	mergeBlocks(segmentTree[index], segmentTree[leftIndex]);
	mergeBlocks(segmentTree[index], segmentTree[rightIndex]);
	
	return;
}

void buildSegmentTree(int left, int right, int index)
{
	if (left == right)
		segmentTree[index] = Block(vals[dfsNode[left]]);
	else
	{
		int middle = (left + right) / 2;

		buildSegmentTree(left, middle, 2 * index);
		buildSegmentTree(middle + 1, right, 2 * index + 1);

		mergeNodes(index);
	}

	return;
}

Block querySegmentTree(int left, int right, int index, const int& leftQ, const int& rightQ)
{
	Block ans;
	
	if (right < leftQ or rightQ < left)
		ans = Block(1);
	else if (leftQ <= left and right <= rightQ)
		ans = segmentTree[index];
	else
	{
		int middle = (left + right) / 2;
		const Block leftBlock = querySegmentTree(left, middle, 2 * index, leftQ, rightQ);
		const Block rightBlock = querySegmentTree(middle + 1, right, 2 * index + 1, leftQ, rightQ);

		mergeBlocks(ans, leftBlock);
		mergeBlocks(ans, rightBlock);
	}

	return ans;
}

pair<Number, Number> querySegmentTree(int left, int right)
{
	Block q = querySegmentTree(0, nodes - 1, 1, left, right);
	

	return make_pair(q.product, countDivisors(q.powerOfPrimes));
}

void updateSegmentTree(int left, int right, int index, const int& indexQ, const Number& seed)
{
	if (indexQ < left or right < indexQ)
		return;
	if (left == right)
	{
		Block aux(seed);
		mergeBlocks(segmentTree[index], aux);
	}
	else
	{
		int middle = (left + right) / 2;
		
		updateSegmentTree(left, middle, 2 * index, indexQ, seed);
		updateSegmentTree(middle + 1, right, 2 * index + 1, indexQ, seed);

		mergeNodes(index);
	}

	return;
}

void updateSegmentTree(int index, const Number& seed)
{
	updateSegmentTree(0, nodes - 1, 1, index, seed);
	
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> nodes;

	fromTo = vector< pair<int, int> >(nodes);
	vals = vector<Number>(nodes);
	dfsNode = vector<int>(nodes);
	dfsId = vector<int>(nodes);
	visited = vector<bool>(nodes);
	segmentTree = vector<Block>(4 * nodes);
	graph = vector< vector<int> >(nodes);
	tree = vector< vector<int> >(nodes);

	for (int i = 0; i < nodes - 1; ++i)
	{
		int u;
		int v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < nodes; ++i)
		cin >> vals[i];

	bfs();

	fill(begin(visited), end(visited), false);
	dfs(0);

	buildSegmentTree(0, nodes - 1, 1);
	
	int q;
	cin >> q;
	while (q--)
	{
		int node;
		string query;
		cin >> query >> node;

		if (query[0] == 'S')
		{
			Number sd;
			cin >> sd;
			updateSegmentTree(dfsId[node], sd);
		}
		else
		{
			pair<Number, Number> ans = querySegmentTree(fromTo[node].first, fromTo[node].second);
			cout << ans.first << " " << ans.second << "\n";
		}
	}

	return 0;
}