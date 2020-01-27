/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 439C - Devu and Partitioning of the Array
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, p;
	cin >> n >> k >> p;

	vector<Long> even;
	vector<Long> odd;

	for (int i = 0; i < n; ++i)
	{
		Long val;
		cin >> val;

		if (val % 2 == 0)
			even.emplace_back(val);
		else
			odd.emplace_back(val);
	}

	vector< vector<Long> > ansSets;

	while (ansSets.size() < p and not even.empty())
	{
		vector<Long> curr(1, even.back());
		ansSets.emplace_back(curr);
		even.pop_back();
	}

	if (not ansSets.empty())
	{
		while (not even.empty())
		{
			const int size = ansSets.size();
			ansSets[size - 1].emplace_back(even.back());
			even.pop_back();
		}
	}

	while (ansSets.size() < p and odd.size() >= 2)
	{
		vector<Long> curr(2);
		
		curr[0] = odd.back();
		odd.pop_back();
		
		curr[1] = odd.back();
		odd.pop_back();

		ansSets.emplace_back(curr);
	}

	string ans = "NO";

	if (ansSets.size() == p)
	{
		while (ansSets.size() < k and not odd.empty())
		{
			vector<Long> curr(1, odd.back());
			odd.pop_back();
			ansSets.emplace_back(curr);
		}

		if (not odd.empty())
		{
			if (k - p > 0)
			{
				if (int(odd.size()) % 2 == 0)
				{
					const int size = ansSets.size();

					for (Long val : odd)
						ansSets[size - 1].emplace_back(val);

				}
				else
					ansSets.clear();
			}
			else
			{
				if (int(odd.size()) % 2 == 0)
				{
					const int size = ansSets.size();

					for (Long val : odd)
						ansSets[size - 1].emplace_back(val);
				}
				else
					ansSets.clear();
			}
		}
		if (not ansSets.empty())
		{
			for (Long val : even)
				ansSets[0].emplace_back(val);
		}
	}

	if (ansSets.size() == k)
		ans = "YES";

	cout << ans << "\n";

	if (ans[0] == 'Y')
	{
		for (auto disjoint : ansSets)
		{
			cout << disjoint.size() << " ";

			for (int val : disjoint)
				cout << val << " ";

			cout << "\n";
		}
	}


	return 0;
}
