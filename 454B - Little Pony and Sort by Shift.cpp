/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 454B - Little Pony and Sort by Shift
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> vals(n);

	for (int i = 0; i < n; ++i)
		cin >> vals[i];

	int ans = 0;

	if (not is_sorted(begin(vals), end(vals)))
	{
		int i = 0;

		while (i + 1 < n and vals[i] <= vals[i + 1])
			++i;

		ans = n - 1 - i;

		for (int j = 0; j < n - 1; ++j)
		{
			i = (i + 1) % n;
			
			if (vals[(i + 1) % n] < vals[i])
			{
				ans = -1;
				break;
			}

		}
	}

	cout << ans << "\n";

	return 0;
}