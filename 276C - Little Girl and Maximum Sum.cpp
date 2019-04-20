/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 276C - Little Girl and Maximum Sum
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long long;

// Least significant one-bit.
inline int LSOne(int n) { return n & (-n); }

struct FenwickTree{
	int size;
	vector<Number> sum;
	vector<Number> values;

	FenwickTree(vector<Number> numbers):size(numbers.size()), sum(size + 1), values(numbers)
	{
		for (int i = 0; i < size; ++i)
			addValue(i, numbers[i]);
	}

	FenwickTree(int n):size(n), sum(n + 1), values(n) {}

	inline void addValue(int index, Number value)
	{
		values[index] += value;
		++index;

		while (index <= size)
		{
			sum[index] += value;
			index += LSOne(index);
		}

		return;
	}

	inline void updateValue(int index, Number value)
	{
		addValue(index, -values[index]);
		addValue(index, value);

		return;
	}

	inline Number getSum(int index)
	{
		++index;
		Number total = 0;

		while (index > 0)
		{
			total += sum[index];
			index -= LSOne(index);
		}

		return total;
	}

	inline Number getSum(int left, int right)
	{
		Number sum = getSum(right);

		if (left <= 0)
			return sum;

		return sum - getSum(left - 1);
	}
};

struct FenwickTreeRange {
	int size;
	FenwickTree sum1;
	FenwickTree sum2;


	FenwickTreeRange(int n):size(n), sum1(n + 1), sum2(n + 1) {}

	inline void addValue(int left, int right, Number value)
	{
		sum1.addValue(left, value);
		sum1.addValue(right + 1, -value);

		sum2.addValue(left, value * (left - 1));
		sum2.addValue(right + 1, -value * right);

		return;
	}

	inline Number getSum(int left, int right)
	{
		Number sum = sum1.getSum(right) * right - sum2.getSum(right);

		if (left <= 0)
			return sum;

		return sum - (sum1.getSum(left - 1) * (left - 1) - sum2.getSum(left - 1));
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<Number> vals(n);

	for (int i = 0; i < n; ++i)
		cin >> vals[i];

	FenwickTreeRange p(n);

	while (q--)
	{
		int left, right;
		cin >> left >> right;

		--left, --right;
		p.addValue(left, right, 1);
	}

	vector<Number> freq(n);

	for (int i = 0; i < n; ++i)
	{
		Number total = p.getSum(i, i);
		freq[i] = total;
	}

	Number maxSum = 0;
	sort(begin(freq), end(freq), greater<Number>());
	sort(begin(vals), end(vals), greater<Number>());


	for (int i = 0; i < n; ++i)
		maxSum += (freq[i] * vals[i]);

	cout << maxSum << "\n";

	return 0;
}