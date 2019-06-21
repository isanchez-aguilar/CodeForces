/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1157A - Reachable Numbers
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Long n;
	cin >> n;

	if (n < 10)
		cout << "9\n";
	else
	{
		Long ans = 0;
		Long minVisited = n + 10;
	
		while (n > 1)
		{
			minVisited = min(minVisited, n);
			
			Long d = n % 10;
			n = (n  + 10 - d);
			ans += 10 - d;
			
			while (n % 10 == 0)
				n /= 10;
		}

		minVisited = min(minVisited, Long(10));

		cout << ans + minVisited - 1 << "\n";
	}

	return 0;
}