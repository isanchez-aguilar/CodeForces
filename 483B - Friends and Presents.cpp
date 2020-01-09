/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 483B - Friends and Presents
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

	Long cnt1, cnt2, x, y;
	cin >> cnt1 >> cnt2 >> x >> y;

	Long minAns = 1;
	Long maxAns = 10000000000000ll;

	Long ans = maxAns;

	while (minAns <= maxAns)
	{
		Long currAns = (minAns + maxAns) / 2ll;

		Long multiplesX = currAns / x;
		Long multiplesY = currAns / y;
		Long multiplesXY = currAns / (x * y);

		Long freeBoth = currAns - (multiplesX + multiplesY - multiplesXY);

		Long aux1 = max(0ll, cnt1 - (currAns - multiplesX - freeBoth));
		Long aux2 = max(0ll, cnt2 - (currAns - multiplesY - freeBoth));
		
		if (aux1 + aux2 <= freeBoth)
		{
			maxAns = currAns - 1;
			ans = currAns;
		}
		else
			minAns = currAns + 1;
	}

	cout << ans << "\n";

	return 0;
}