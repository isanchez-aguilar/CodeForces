/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 479D - Long Jumps
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, l, x, y;

	cin >> n >> l >> x >> y;

	set<int> positions;
	vector<int> marks(n);
	
	for (int i = 0; i < n; ++i)
	{
		cin >> marks[i];
		positions.insert(marks[i]);
	}

	bool solved1 = false;
	bool solved2 = false;

	for (int mark : marks)
	{
		if ((positions.count(mark - x) != 0 or positions.count(mark + x) != 0))
			solved1 = true;

		if (positions.count(mark - y) != 0 or positions.count(mark + y) != 0)
			solved2 = true;

		if (solved1 and solved2)
			break;
	}

	if (solved1 and solved2)
		cout << "0\n";
	else
	{
		if (solved1)
			cout << "1\n" << marks[0] + y << "\n";
		else if (solved2)
			cout << "1\n" << marks[0] + x << "\n";
		else
		{
			vector<int> ans;



			for (int i = 0; i < n; ++i)
			{
				int p = marks[i] - x;

				if (p >= 0 and p <= l and (positions.count(p - y) != 0 or positions.count(p + y) != 0))
				{
					ans.emplace_back(p);
					break;
				}

				p = marks[i] + x;

				if (p >= 0 and p <= l and (positions.count(p - y) != 0 or positions.count(p + y) != 0))
				{
					ans.emplace_back(p);
					break;
				}
			}

			if (ans.size() == 0)
			{
				ans.emplace_back(marks[0] + y);
				ans.emplace_back(marks[0] + x);
			}

			cout << ans.size() << "\n";

			for (int p : ans)
				cout << p << " ";

			cout << "\n";
		}
	}



	return 0;
}
