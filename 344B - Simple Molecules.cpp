/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 344B - Simple Molecules
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map< pair<int, int>, int > ansIndex;

	ansIndex[{0, 1}] = 0;
	ansIndex[{1, 0}] = 0;
	ansIndex[{1, 2}] = 1;
	ansIndex[{2, 1}] = 1;
	ansIndex[{0, 2}] = 2;
	ansIndex[{2, 0}] = 2;

	int sum = 0;
	vector< pair<int, int> > nodes(3);

	for (int i = 0; i < 3; ++i)
	{
		cin >> nodes[i].first;

		nodes[i].second = i;
		sum += nodes[i].first;
	}


	vector<int> ans(3);
	bool possible = true;

	sort(begin(nodes), end(nodes), greater< pair<int, int> >());

	int a = nodes[0].second;
	int b = nodes[1].second;


	int diff = min(nodes[0].first, nodes[1].first - nodes[2].first);

	nodes[0].first -= diff;
	nodes[1].first -= diff;

	ans[ansIndex[{a, b}]] += diff;

	int parts = min(nodes[0].first / 2, min(nodes[1].first, nodes[2].first));

	nodes[0].first -= 2 * parts;
	nodes[1].first -= parts;
	nodes[2].first -= parts;

	ans[ansIndex[{a, b}]] += parts;
	
	a = nodes[0].second;
	b = nodes[2].second;

	ans[ansIndex[{a, b}]] += parts;


	a = nodes[1].second;
	b = nodes[2].second;

	ans[ansIndex[{a, b}]] += nodes[1].first;

	if (nodes[0].first != 0)
		possible = false;

	if (possible)
	{
		for (int v : ans)
			cout << v << " ";
	}
	else
		cout << "Impossible\n";

	return 0;
}