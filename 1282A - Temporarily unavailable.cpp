/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1282A - Temporarily unavailable
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int testCases;
	cin >> testCases;

	while (testCases--)
	{
		Long a, b, c, r;
		cin >> a >> b >> c >> r;

		Long lSide = c - r;
		Long rSide = c + r;

		Long offset = min(lSide, a);
		offset = min(offset, b);

		offset = abs(offset);

		a += offset;
		b += offset;
		lSide += offset;
		rSide += offset;


		if (b < a)
			swap(a, b);

		Long ans = b - a;

		if (not (rSide <= a) and not (b <= lSide))
		{
			if (lSide <= a and b <= rSide)
				ans = 0;
			else if (a <= lSide)
			{
				if (rSide <= b)
					ans -= (rSide - lSide);
				else
					ans -= (b - lSide);
			}
			else
			{
				if (a <= lSide)
					ans -= (rSide - lSide);
				else
					ans -= (rSide - a);
			}
		}

		cout << ans << "\n";
	}

	return 0;
}