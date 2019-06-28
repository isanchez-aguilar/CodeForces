/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 218B - Airport
*/
#include <bits/stdc++.h>

using namespace std;
using Long  = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	multiset<int> seats1;
	multiset<int> seats2;

	for (int i = 0; i < m; ++i)
	{
		int s;
		cin >> s;

		seats1.insert(s);
		seats2.insert(s);
	}

	int maxCost = 0;
	int currentPeople = n;
	
	for (int i = 0; i < n; ++i)
	{
		multiset<int>::iterator greatest = --end(seats1);

		int cost = *greatest;
		maxCost += cost;

		seats1.erase(greatest);
		
		if (cost - 1 > 0)
			seats1.insert(cost - 1);
	}

	int minCost = 0;

	for (int i = 0; i < n; ++i)
	{
		multiset<int>::iterator lowest = begin(seats2);

		int cost = *lowest;
		minCost += cost;


		seats2.erase(lowest);
		
		if (cost - 1 > 0)
			seats2.insert(cost - 1);
	}	

	cout << maxCost << " " << minCost << "\n";


	return 0;
}