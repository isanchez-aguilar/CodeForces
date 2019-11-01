/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 401C - Team
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int i = 0;
	int extra = 0;
	string ans = "";
	int block = m / n;

	if (block >= 3)
	{
		block = (m - 2) / n;
		ans = string(2, '1');
		m -= 2;
	}
	else if (m % n > 0)
	{
		if (block < 2)
			extra = m % n;
		else
		{
			ans += string(2, '1');
			m -= 2;
		}
	}

	if (block >= 3)
		ans = "-1";
	else
	{
/*		if (block == 0 and m > 0)
			++block;*/

		while (true)
		{
			if (n <= 0 and m <= 0)
				break;

			if (n > 0)
			{
				--n;
				ans += '0';
			}
			if (m > 0)
			{
				int ones = min(block, m);

				if (extra > 0)
					++ones, --extra;

				ans += string(ones, '1');
				m -= ones;
			}
		}

		bool good = true;

		for (int i = 1; i < int(ans.size()); ++i)
		{
			if (ans[i] == '0' and ans[i - 1] == '0')
			{
				good = false;
				break;
			}
			else if (i > 1 and ans[i] == '1' and ans[i - 1] == '1' and ans[i - 1] == ans[i - 2])
			{
				good = false;
				break;
			}
		}

		if (not good)
			ans = "-1";
	}

	cout << ans << "\n"; 

	return 0;
}