/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 416C - Booking System
*/
#include <bits/stdc++.h>

using namespace std;
using Long = int;
using ii = pair<Long, Long>;

struct Group {
	Long index, people, money;
};

inline bool cmp(const Group& a, const Group& b)
{
	if (a.money == b.money)
		return a.people < b.people;

	return a.money > b.money;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int groups;
	cin >> groups;

	vector<Group> groupsInfo(groups);

	for (int i = 0; i < groups; ++i)
	{
		auto& v = groupsInfo[i];
		v.index = i + 1;
		cin >> v.people >> v.money;
	}

	sort(begin(groupsInfo), end(groupsInfo), cmp); 

	int tables;
	cin >> tables;

	set< pair<Long, int> > tablesSize;

	for (int i = 0; i < tables; ++i)
	{
		Long v;
		cin >> v;

		tablesSize.insert({v, i + 1});
	}

	ii ans(0, 0);
	vector<ii> ansTables; 

	for (auto& p : groupsInfo)
	{
		if (tablesSize.empty())
			break;

		//cerr << p.people << ":" << p.money << "," << maxPeople << endl;
		auto it = tablesSize.lower_bound({p.people, -1});

		//cerr << (it == end(tablesSize)) << " " << maxPeople << "," << p.people << endl;

		if (it != end(tablesSize))
		{
			++ans.first;
			ans.second += p.money;
			ansTables.emplace_back(p.index, it->second);
			tablesSize.erase(it);
		}
	}

	cout << ans.first << " " << ans.second << "\n";

	for (auto& p : ansTables)
		cout << p.first << " " << p.second << "\n";

	return 0;
}