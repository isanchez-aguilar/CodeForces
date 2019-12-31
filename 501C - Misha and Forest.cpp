/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 501C - Misha and Forest
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

	vector< pair<int, int> > nodes(n);

	for (int i = 0; i < n; ++i)
		cin >> nodes[i].first >> nodes[i].second;

	queue<int> remainingOne;

	for (int i = 0; i < n; ++i)
	{
		if (nodes[i].first == 1)
			remainingOne.push(i);
	}

	vector< pair<int, int> > ans;

	while (not remainingOne.empty())
	{
		int currNode = remainingOne.front();
		remainingOne.pop();

		pair<int, int>& node = nodes[currNode];
		
		if (node.first > 0)
		{
			int v = node.second;
			ans.emplace_back(currNode, v);

			--node.first;
			node.second = 0;

			--nodes[v].first;
			nodes[v].second ^= currNode;

			if (nodes[v].first == 1)
				remainingOne.push(v);
		}
	}


	cout << ans.size() << "\n";

	for (auto p : ans)
		cout << p.first << " " << p.second << "\n";

	return 0;
}