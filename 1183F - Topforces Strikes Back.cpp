/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1183F - Topforces Strikes Back
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	while (q--)
	{
		int n;
		cin >> n;
		set< int, greater<int> > vals;

		for (int i = 0; i < n; ++i)
		{
			int val;
			cin >> val;
			vals.insert(val);
		}

		int ans = 0;
		int aux = *begin(vals);

		if (aux % 2 == 0 and aux % 3 == 0 and aux % 5 == 0)
		{
			if (vals.count(aux / 2) > 0 and vals.count(aux / 3) > 0 and vals.count(aux / 5) > 0)
				ans = aux / 2 + aux / 3 + aux / 5;
		}

		vector<int> problems;

		while (not vals.empty() and problems.size() < 3)
		{
			int v = *begin(vals);
			vals.erase(begin(vals));

			bool isDivisible = false;

			for (int d : problems)
				isDivisible |= (d % v == 0);
			
			if (not isDivisible)
				problems.push_back(v);
		}

		ans = max(ans, accumulate(begin(problems), end(problems), 0));

		cout << ans << "\n";
	}

	return 0;
}