/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 382C - Arithmetic Progression
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using Long = long long;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> ans;

	if (n == 1)
		ans.emplace_back(-1);
	else
	{
		sort(begin(a), end(a));

		if (a[0] == a[n - 1])
			ans.emplace_back(a[0]);
		else
		{
			int div = (a[n - 1] - a[0]) / (n - 1);

			bool good = true;

			for (int i = 1; i < n; ++i)
			{
				if (a[i - 1] + div != a[i])
				{
					good = false;
					break;
				}
			}

			if (good)
			{
				ans.emplace_back(a[0] - div);
				ans.emplace_back(a[n - 1] + div);
			}

			div = (a[n - 1] - a[0]) / n;

			good = true;
			int toInsert;
			bool used = false;


			for (int i = 0; i < n - 1; ++i)
			{
				if (a[i] + div != a[i + 1])
				{
					toInsert = a[i] + div;

					if (used or toInsert + div != a[i + 1])
					{
						good = false;
						break;
					}
					else
						used = true;
				}
			}

			if (good)
				ans.emplace_back(toInsert);
		
			sort(begin(ans), end(ans));
			unique(begin(ans), end(ans));
		}
	}

	if (n != 1)
		cout << ans.size() << "\n";


	for (int v : ans)
		cout << v << " ";

	cout << "\n";

	return 0;
}