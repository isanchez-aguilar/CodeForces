#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Number sides;
	pair<Number, Number> p1;
	pair<Number, Number> p2;

	cin >> sides;
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;

	Number total = 0;

	if (p1 == p2)
		total = sides / 2;
	else
	{
		Number dx = abs(p1.first - p2.first);
		Number dy = abs(p1.second - p2.second);

		total = sides - dx - dy + 1;

		if (total > 0)
			total = ceil((double)total / 2.0);
		else
			total = 0;
	}

	cout << total << "\n";

	return 0;
}