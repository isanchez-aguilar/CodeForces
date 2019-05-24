#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int testCases;
	cin >> testCases;

	Number p[3];
	
	while (testCases--)
	{
		int n, k;
		cin >> n >> k;

		vector<Number> price(2 * n);

		for (int i = 0; i < n; ++i)
		{

			for (int j = 0; j < 3; ++j)
				cin >> p[j];

			sort(begin(p), end(p));

			price[2 * i] = p[0];
			price[2 * i + 1] = p[1];
		}

		sort(begin(price), end(price));

		cout << accumulate(begin(price), begin(price) + k, 0) << "\n";
	}

	return 0;
}