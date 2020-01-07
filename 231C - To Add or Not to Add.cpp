/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 231C - To Add or Not to Add
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	Long k;
	cin >> n >> k;

	vector<Long> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	


	sort(begin(a), end(a));

	vector<Long> accum(n);

	accum[0] = a[n - 1] - a[0];

	for (int i = 1; i < n; ++i)
	{
		accum[i] = accum[i - 1];
		accum[i] += a[n - 1] - a[i];
	}

	pair<Long, Long> ans(count(begin(a), end(a), a[0]), a[0]);

	for (int i = 1; i < n; ++i)
	{
		if (i == n - 1 or a[i] != a[i + 1])
		{
			int minEl = 0;
			int maxEl = i;


			pair<Long, Long> currAns(-1, a[i]);

			while (minEl <= maxEl)
			{
				int currEl = (minEl + maxEl) / 2;

				Long needOp = accum[i - 1] - (currEl == i?0:accum[i - currEl - 1]);

				needOp -= (a[n - 1] - a[i]) * currEl;

				//cerr << a[i] << "=>" << currEl << ":" << i - currEl - 1 << "->" << needOp << "?" << (a[n - 1] - a[i]) * currEl << "\n";

				if (needOp <= k)
				{
					currAns.first = currEl + 1;
					minEl = currEl + 1;
				}
				else
					maxEl = currEl - 1;
			}

			if (ans.first < currAns.first)
				ans = currAns;
		}
	}

	cout << ans.first << " " << ans.second << "\n";

	return 0;
}