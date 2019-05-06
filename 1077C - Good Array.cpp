/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1077C - Good Array
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	Number totalSum = 0;
	vector< pair<Number, int> > data(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> data[i].first;

		data[i].second = i;
		totalSum += data[i].first;
	}

	vector<int> ans; 
	sort(begin(data), end(data));

	for (int i = 0; i < n; ++i)
	{
		const Number doubleMissingValue = totalSum - data[i].first;

		if (doubleMissingValue % 2ll == 0)
		{
			vector< pair<Number, int> >::iterator it = lower_bound(begin(data), end(data), make_pair(doubleMissingValue / 2ll, -1));

			if (it != end(data))
			{
				if (it->first == doubleMissingValue / 2ll)
				{
					if (it->second != data[i].second or (it != --end(data) and (++it)->first == doubleMissingValue / 2ll))
						ans.push_back(data[i].second + 1);
				}
			}
		}
	}

	cout << ans.size() << "\n";

	for (int i = 0; i < (int)ans.size(); ++i)
		cout << (i == 0?"":" ") << ans[i];

	return 0;
}