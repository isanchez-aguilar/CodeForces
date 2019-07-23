/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1154E - Two Teams
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector< pair<int, int> > skills(n);
	
	for (int i = 0; i < n; ++i)
	{
		cin >> skills[i].first;
		skills[i].second = i;
	}

	sort(begin(skills), end(skills), greater< pair<int, int> >());

	set<int> available;
	string ans(n, '0');
	int currentTeam = 0;
	queue<int> remaining;

	for (int i = 0; i < n; ++i)
	{
		available.insert(i);
		remaining.push(skills[i].second);
	}


	while (not available.empty())
	{
		while (available.count(remaining.front()) == 0)
			remaining.pop();

		int index = remaining.front();
		remaining.pop();

		vector<int> selected(1, index);
		set<int>::iterator j = available.find(index);

		for (int i = 0; i < k and j != begin(available); ++i)
		{
			--j;
			selected.push_back(*j);
		}

		j = available.find(index);

		for (int i = 0; i < k and j != prev(end(available)); ++i)
		{
			++j;
			selected.push_back(*j);
		}

		for (int v : selected)
		{
			ans[v] = '1' + currentTeam;
			available.erase(v);
		}

		currentTeam ^= 1;
	}

	cout << ans << "\n";

	return 0;
}