/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 479C - Exams
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using Long = long long;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector< pair<int, int> > vals(n);

	for (int i = 0; i < n; ++i)
		cin >> vals[i].first >> vals[i].second;

	
	sort(begin(vals), end(vals));

	int i = 0;
	int prev = -1;

	while (i < n)
	{
		if (prev <= vals[i].first and prev <= vals[i].second)
			prev = min(vals[i].first, vals[i].second);
		else if (prev <= vals[i].first)
			prev = vals[i].first;
		else
			prev = vals[i].second;

		++i;
	}

	cout << prev << "\n";

	return 0;
}
