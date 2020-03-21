/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 279C - Ladder
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int size, queries;
	cin >> size >> queries;

	vector<Long> vals(size);

	for (auto& v : vals)
		cin >> v;

	vector<int> startIncreasing(size);
	vector<int> startDecreasing(size);

	for (int i = 1; i < size; ++i)
	{
		if (vals[i - 1] <= vals[i])
			startIncreasing[i] = startIncreasing[i - 1];
		else
			startIncreasing[i] = i;

		if (vals[i] <= vals[i - 1])
			startDecreasing[i] = startDecreasing[i - 1];
		else
			startDecreasing[i] = i;
	}

	while (queries--)
	{
		int l, r;
		cin >> l >> r;
		--l, --r;

		int startDec = startDecreasing[r];

		if (startDec <= l or startIncreasing[startDec] <= l)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}