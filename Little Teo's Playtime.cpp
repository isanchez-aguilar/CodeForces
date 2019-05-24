#include <bits/stdc++.h>

using namespace std;
using Number = int;

struct SegmentTree
{
	int size;
	vector<Number> data;
	SegmentTree* leftNode;
	SegmentTree* rightNode;
	pair<Number, Number> longestPrefix;
	pair<Number, Number> longestPosfix;
	pair<Number, Number> longestSubarray;

	SegmentTree(){}

	SegmentTree(SegmentTree* _leftNode, SegmentTree* _rightNode):leftNode(_leftNode), rightNode(_rightNode)
	{
		size = leftNode->size + rightNode->size;
		data.insert(data.end(), begin(leftNode->data), end(leftNode->data));
		data.insert(data.end(), begin(rightNode->data), end(rightNode->data));
		
		updateSegment();
	}

	SegmentTree(vector<Number> values):data(values), size(values.size())
	{
		leftNode = NULL;
		rightNode = NULL;

		buildSegmentTree(0, size - 1);
	}

	void buildSegmentTree(int leftIndex, int rightIndex)
	{
		if (leftIndex == rightIndex)
		{
			longestPrefix.first = 1;
			longestPosfix.first = 1;
			longestSubarray.first = 1;
			longestPrefix.second = data[leftIndex];
			longestPosfix.second = data[leftIndex];
			longestSubarray.second = data[leftIndex];
		}
		else		
		{
			int middle = (leftIndex + rightIndex) / 2;

			vector<Number> leftSegment(begin(data), begin(data) + middle + 1);
			vector<Number> rightSegment(begin(data) + middle + 1, end(data));
			
			leftNode = new SegmentTree(leftSegment);
			rightNode = new SegmentTree(rightSegment);
			
			updateSegment();
		}

		return;
	}

	void swapValues(int x, int y)
	{
		Number aux = data[x];

		updateValue(0, size - 1, x, data[y]);
		updateValue(0, size - 1, y, aux);
		
		return;
	}

	void updateValue(int leftIndex, int rightIndex, int index, const Number& value)
	{
		if (leftIndex == rightIndex)
		{
			data[leftIndex] = value;
			longestPrefix.first = 1;
			longestPosfix.first = 1;
			longestSubarray.first = 1;
			longestPrefix.second = data[leftIndex];
			longestPosfix.second = data[leftIndex];
			longestSubarray.second = data[leftIndex];
		}
		else		
		{
			int middle = (leftIndex + rightIndex) / 2;
			


			if (index <= middle)
				leftNode->updateValue(0, middle, index, value);
			else
				rightNode->updateValue(0, middle, index - middle - 1, value);

			data[index] = value;
			updateSegment();
		}
	}

	inline void updateSegment()
	{
		longestPrefix = leftNode->longestPrefix;
		longestPosfix = rightNode->longestPosfix;
		longestSubarray = max(leftNode->longestSubarray, rightNode->longestSubarray);

		if (leftNode->longestPrefix.first == leftNode->size and leftNode->longestPrefix.second == rightNode->longestPrefix.second)
			longestPrefix.first += rightNode->longestPrefix.first;

		if (rightNode->longestPosfix.first == rightNode->size and rightNode->longestPosfix.second == leftNode->longestPosfix.second)
			longestPosfix.first += leftNode->longestPosfix.first;

		if (leftNode->longestPosfix.second == rightNode->longestPrefix.second)
		{
			pair<Number, Number> currentSubarray(leftNode->longestPosfix);
			currentSubarray.first += rightNode->longestPrefix.first;

			longestSubarray = max(longestSubarray, currentSubarray);
		}
		return;
	}

	Number getLongestSubArray()
	{
		return longestSubarray.first;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int amountOfSnakes, queries;
	cin >> amountOfSnakes >> queries;

	vector<SegmentTree*> snakes(amountOfSnakes);

	for (int i = 0; i < amountOfSnakes; ++i)
	{
		int size;
		cin >> size;

		vector<int> colours(size);

		for (int i = 0; i < size; ++i)
			cin >> colours[i];
	
		snakes[i] = new SegmentTree(colours);
	}

	while (queries--)
	{
		short type;
		cin >> type;

		if (type == 1)
		{
			int x, y;
			int indexOfSnake;
			cin >> x >> y >> indexOfSnake;
			snakes[indexOfSnake - 1]->swapValues(x - 1, y - 1);
		}	
		else if (type == 2)
		{
			int left, right;
			cin >> left >> right;

			snakes.push_back(new SegmentTree(snakes[left - 1], snakes[right - 1]));
		}
		else
		{
			int indexOfSnake;
			cin >> indexOfSnake;

			if (type == 3)
			{
				snakes.push_back(snakes[indexOfSnake - 1]->leftNode);
				snakes.push_back(snakes[indexOfSnake - 1]->rightNode);
			}
			else
				cout << snakes[indexOfSnake - 1]->getLongestSubArray() << "\n";
		}
	}

	return 0;
}