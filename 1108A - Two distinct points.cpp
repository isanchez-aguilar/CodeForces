/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1108A - Two distinct points
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	vector< pair<int, int> > seg(2);

	while (q--)
	{
		cin >> seg[0].first >> seg[0].second;
		cin >> seg[1].first >> seg[1].second;

		if (seg[0] == seg[1])
			cout << seg[0].first << " " << seg[0].second << "\n";
		else if (seg[0] < seg[1])
		{
			if (seg[1].second <= seg[0].second)
				cout << seg[1].first << " " << seg[1].second << "\n";
			else if (seg[1].first <= seg[0].second)
				cout << seg[1].first << " " << seg[1].second << "\n";
			else
				cout << seg[0].first << " " << seg[1].second << "\n";
		}
		else
		{
			if (seg[0].second <= seg[1].second)
				cout << seg[0].first << " " << seg[0].second << "\n";
			else if (seg[0].first <= seg[1].second)
				cout << seg[0].second << " " << seg[1].first << "\n";
			else
				cout << seg[0].second << " " << seg[1].first << "\n";
		}
	}

	return 0;
}