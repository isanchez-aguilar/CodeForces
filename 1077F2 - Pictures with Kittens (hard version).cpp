/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1077F2 - Pictures with Kittens (hard version)
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long long;

class QueueMax {
public:
	stack< pair<Number, Number> > popQueue;
	stack< pair<Number, Number> > pushQueue; 

	QueueMax(){}

	inline bool empty()
	{
		return popQueue.empty() and pushQueue.empty();
	}

	inline Number getMax()
	{
		Number maxVal = -1;
		
		if (not empty())
		{
			if (not popQueue.empty() and not pushQueue.empty())
				maxVal = max(popQueue.top().first, pushQueue.top().first);
			else if (not popQueue.empty())
				maxVal = popQueue.top().first;
			else
				maxVal = pushQueue.top().first;
		}

		return maxVal;
	}

	inline void push(const Number& val)
	{
		if (pushQueue.empty())
			pushQueue.push(make_pair(val, val));
		else
			pushQueue.push(make_pair(max(val, pushQueue.top().first), val));

		return;
	}

	inline void pop()
	{
		if (popQueue.empty())
		{
			while (not pushQueue.empty())
			{
				pair<Number, Number> val;
				if (popQueue.empty())
					val = make_pair(pushQueue.top().second, pushQueue.top().second);
				else
					val = make_pair(max(popQueue.top().first, pushQueue.top().second), pushQueue.top().second);

				popQueue.push(val);
				pushQueue.pop();
			}
		}

		popQueue.pop();

		return;
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, k;
	cin >> n >> k >> x;

	vector<Number> beauty(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> beauty[i];

	vector<QueueMax> previousMax(x + 1);
	vector< queue<int> > previousPos(x + 1);
	vector< vector<Number> > memo(n + 1, vector<Number>(x + 1, -1));

	memo[0][0] = 0;
	previousPos[0].push(0);
	previousMax[0].push(0);

	for (int i = 1; i <= n; ++i)
	{
		for (int currentCards = 0; currentCards <= x; ++currentCards)
		{
			while (not previousPos[currentCards].empty() and previousPos[currentCards].front() < i - k)
			{
				previousPos[currentCards].pop();
				previousMax[currentCards].pop();
			}
		}

		for (int currentCards = x; currentCards >= 1; --currentCards)
		{
			if (not previousMax[currentCards - 1].empty())
			{
				memo[i][currentCards] = max(memo[i][currentCards], previousMax[currentCards - 1].getMax() + beauty[i]);
				previousMax[currentCards].push(memo[i][currentCards]);
				previousPos[currentCards].push(i);
			}
		}
	}

	Number ans = -1;

	for (int i = n - k + 1; i <= n; ++i)
		ans = max(ans, *max_element(begin(memo[i]), end(memo[i])));

	cout << ans << "\n";

	return 0;
}