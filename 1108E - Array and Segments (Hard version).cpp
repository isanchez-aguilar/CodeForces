/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1108E - Array and Segments (Hard version)
*/
#include <bits/stdc++.h>

#define MIN_VAL LONG_MIN
#define MAX_VAL LONG_MAX

using namespace std;
using Long = long;

class SegmentTree {
public:
	int size;
	vector<Long> tree;
	vector<Long> data;
	vector<Long> lazy;

	SegmentTree(const vector<Long>& values):data(values), tree(4 * values.size()), lazy(4 * values.size())
	{
		size = (int)data.size();
		buildSegmentTree(0, size - 1, 1);
	}

	void buildSegmentTree(const int& leftIndex, const int& rightIndex, const int& node)
	{
		if (leftIndex == rightIndex)
			tree[node] = data[leftIndex];
		else
		{
			const int leftNode = 2 * node;
			const int rightNode = 2 * node + 1;
			const int middleIndex = getMiddle(leftIndex, rightIndex);
			
			buildSegmentTree(leftIndex, middleIndex, leftNode);
			buildSegmentTree(middleIndex + 1, rightIndex, rightNode);
			mergeNodes(node, leftNode, rightNode);
		}

		return;
	}

	void updateRange(const int left, const int right)
	{
		updateRange(0, size - 1, 1, left, right);

		return;
	}

	void updateRange(const int leftIndex, const int rightIndex, const int node, const int& left, const int& right)
	{
		int leftNode = 2 * node;
		int rightNode = 2 * node + 1;

		updateLazy(node, leftNode, rightNode, leftIndex == rightIndex);

		if (not (rightIndex < left or right < leftIndex))
		{	
			if (left <= leftIndex and rightIndex <= right)
			{
				if (leftIndex != rightIndex)
				{
					--lazy[leftNode];
					--lazy[rightNode];
				}

				--tree[node];
			}
			else
			{
				int middleIndex = getMiddle(leftIndex, rightIndex);

				updateRange(leftIndex, middleIndex, leftNode, left, right);
				updateRange(middleIndex + 1, rightIndex, rightNode, left, right);
				mergeNodes(node, leftNode, rightNode);
			}
		}

		return;
	}

	Long query(const int left, const int right)
	{
		return query(0, size - 1, 1, left, right);
	}

	Long query(const int leftIndex, const int rightIndex, const int node, const int& left, const int& right)
	{
		int ans = 0;
		int leftNode = 2 * node;
		int rightNode = 2 * node + 1;

		updateLazy(node, leftNode, rightNode, leftIndex == rightIndex);

		if (rightIndex < left or right < leftIndex)
			ans = MAX_VAL;
		else if (left <= leftIndex and rightIndex <= right)
			ans = tree[node];
		else
		{
			int middleIndex = getMiddle(leftIndex, rightIndex);

			Long leftAns = query(leftIndex, middleIndex, leftNode, left, right);
			Long rightAns = query(middleIndex + 1, rightIndex, rightNode, left, right);

			return min(leftAns, rightAns);
		}

		return ans;
	} 

	void updateLazy(const int& node, const int& leftNode, const int& rightNode, bool isLeaf)
	{
		if (lazy[node] != 0)
		{
			tree[node] += lazy[node];
				
			if (not isLeaf)
			{
				lazy[leftNode] += lazy[node];
				lazy[rightNode] += lazy[node];
			}

			lazy[node] = 0;
		}

		return;
	}

	void mergeNodes(const int& node, const int& leftNode, const int& rightNode)
	{
		tree[node] = min(tree[leftNode], tree[rightNode]);
		
		return;
	}

	int getMiddle(int a, int b)
	{
		return (a + b) >> 1;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<Long> data(n);

	for (int i = 0; i < n; ++i)
		cin >> data[i];

	vector< vector<int> > endSg(n);
	vector< pair<int, int> > sg(m);
	vector< vector<int> > startSg(n);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		--a, --b;
		sg[i].first = a;
		sg[i].second = b;
		endSg[b].push_back(a);
		startSg[a].push_back(b);
	}

	SegmentTree helper(data);

	Long minValue = data[0];
	vector<Long> ansPositions(n, MIN_VAL);

	for (int i = 0; i < n; ++i)
	{
		ansPositions[i] = max(ansPositions[i], data[i] - minValue);

		for (int j = 0; j < (int)endSg[i].size(); ++j)
			helper.updateRange(endSg[i][j], i);

		minValue = min(minValue, helper.query(0, i));
	}

	helper = SegmentTree(data);
	minValue = data[n - 1];

	for (int i = n - 1; i > -1; --i)
	{
		ansPositions[i] = max(ansPositions[i], data[i] - minValue);

		for (int j = 0; j < (int)startSg[i].size(); ++j)
			helper.updateRange(i, startSg[i][j]);

		minValue = min(minValue, helper.query(i, n - 1));
	}

	vector<int> ansIndex;
	Long ans = *max_element(begin(ansPositions), end(ansPositions));
	
	for (int i = 0; i < n; ++i)
	{
		if (ans == ansPositions[i])
		{
			for (int j = 0; j < m; ++j)
			{
				if (not (sg[j].first <= i and i <= sg[j].second))
					ansIndex.push_back(j + 1);
			}

			break;
		}
	}

	cout << ans << "\n" << ansIndex.size() << "\n";

	for (int i = 0; i < (int)ansIndex.size(); ++i)
		cout << ansIndex[i] << (i == ansIndex.size() - 1?"\n":" ");


	return 0;
}