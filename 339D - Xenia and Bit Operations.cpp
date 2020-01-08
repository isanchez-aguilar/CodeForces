/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 339D - Xenia and Bit Operations
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using Long = long long;

struct SegmentTree {
	int size;
	vector<int> data;
	vector<int> tree;

	SegmentTree(const vector<int>& a):data(a), size(a.size()), tree(4 * a.size())
	{
		build(0, size - 1, 1);
	}

	short build(int leftIdx, int rightIdx, int treeIdx)
	{
		short operation = 0;

		if (leftIdx == rightIdx)
		{
			tree[treeIdx] = data[leftIdx];
			operation = 1;
		}
		else
		{
			const int leftTree = 2 * treeIdx;
			const int rightTree = 2 * treeIdx + 1;
			const int middle = (leftIdx + rightIdx) / 2;

			operation = build(leftIdx, middle, leftTree);
			operation = build(middle + 1, rightIdx, rightTree);

			mergetChildren(treeIdx, operation);
		}

		return 1 - operation;
	}

	int update(int i, int val)
	{
		update(0, size - 1, 1, i, val);

		return getAns();
	}

	short update(int leftIdx, int rightIdx, int treeIdx, const int index, const int val)
	{
		short operation = 0;

		if (leftIdx == rightIdx)
		{
			data[index] = val;
			tree[treeIdx] = val;
			operation = 1;
		}
		else
		{
			const int middle = (leftIdx + rightIdx) / 2;

			if (leftIdx <= index and index <= middle)
				operation = update(leftIdx, middle, 2 * treeIdx, index, val);
			else
				operation = update(middle + 1, rightIdx, 2 * treeIdx + 1, index, val);

			mergetChildren(treeIdx, operation);
		}

		return 1 - operation;
	}

	inline void mergetChildren(int idx, short operation)
	{
		if (operation == 0)
			tree[idx] = tree[2 * idx] | tree[2 * idx + 1];
		else
			tree[idx] = tree[2 * idx] ^ tree[2 * idx + 1];

	}

	inline int getAns()
	{
		return tree[1];
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	const int size = 1 << n;
	vector<int> a(1 << n);

	for (int i = 0; i < size; ++i)
		cin >> a[i];

	SegmentTree helper(a);

	while (q--)
	{
		int i, v;
		cin >> i >> v;

		cout << helper.update(i - 1, v) << "\n";
	}

	return 0;
}