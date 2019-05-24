#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> minRows(n);

	for (int i = 0; i < n; ++i)
	{
		minRows[i] = INT_MAX;

		for (int j = 0; j < n; ++j)
		{
			int val;
			cin >> val;
			minRows[i] = min(minRows[i], val);
		}
	}

	cout << *max_element(begin(minRows), end(minRows)) << "\n";

	return 0;
}