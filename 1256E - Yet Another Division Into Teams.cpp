/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1256E - Yet Another Division Into Teams
*/
#include <bits/stdc++.h>

#define INF 10000000000

using namespace std;
using Long = long long;
 
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 

	int n;
	cin >> n;

	vector< pair<Long, int> > skills(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> skills[i].first;
		skills[i].second = i;
	}

	sort(begin(skills), end(skills));

	Long totDiversity = 0;

	vector< pair<Long, Long> > memo(n);

	memo[0] = memo[1] = {INF, skills[0].first};
	memo[2] = {skills[2].first - skills[0].first, skills[0].first};

	for (int i = 3; i < n; ++i)
	{
		memo[i] = {
			skills[i].first + memo[i - 1].first - skills[i - 1].first,
			memo[i - 1].second
		};

		if (i - 2 > 2)
		{
			Long newDiversity = skills[i].first - skills[i - 2].first  + memo[i - 3].first;
			
			if (newDiversity < memo[i].first)
			{
				memo[i] = {
					newDiversity,
					skills[i - 2].first
				};
			}
		}
	}

	int teams = 0;
	vector<int> ans(n);

	totDiversity = memo[n - 1].first;

	
	int i = n - 1;

	while (i >= 0)
	{
		++teams;
		Long minSkill = memo[i].second;
		
		while (i >= 0 and minSkill != skills[i].first)
		{
			ans[skills[i].second] = teams;
			--i;
		}

		while (i >= 0 and minSkill == skills[i].first)
		{
			ans[skills[i].second] = teams;
			--i;
		}
	}


	cout << totDiversity << " " << teams << "\n";

	for (int v : ans)
		cout << v << " ";
	cout << "\n";

	return 0;
}