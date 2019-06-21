/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1157F - Maximum Balanced Circle
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> vals(n);
	vector<int> freq(200001);

	for (int i = 0; i < n; ++i)
	{
		cin >> vals[i];
		++freq[vals[i]];
	}

	sort(begin(vals), end(vals));
	vals.resize(unique(begin(vals), end(vals)) - begin(vals));

	n = vals.size();
	int leftIndex = 0;
	int rightIndex = 0;
	int ans = freq[vals[0]];

	for (int i = 0; i < n; ++i)
	{
		int j = i + 1;
		int sum = freq[vals[i]];

		while (j < n and vals[j] - vals[j - 1] == 1 and freq[vals[j]] > 1)
		{
			sum += freq[vals[j]];
			++j;
		}

		int currentRight = j - 1;

		if (j < n and vals[j] - vals[j - 1] == 1)
		{
			currentRight = j;
			sum += freq[vals[j]];
		}

		if (ans < sum)
		{
			ans = sum;
			leftIndex = i;
			rightIndex = currentRight;
		}

		i = j - 1;
	}

	cout << ans << "\n";

	for (int i = 0; i < freq[vals[leftIndex]]; ++i)
		cout << vals[leftIndex] << " ";

	for (int i = leftIndex + 1; i < rightIndex; ++i)
	{
		for (int j = 0; j < freq[vals[i]] - 1; ++j)
			cout << vals[i] << " ";
	}

	for (int i = 0; leftIndex != rightIndex and i < freq[vals[rightIndex]]; ++i)
		cout << vals[rightIndex] << " ";

	for (int i = rightIndex - 1; i > leftIndex; --i)
		cout << vals[i] << " ";

	cout << "\n";

	return 0;
}