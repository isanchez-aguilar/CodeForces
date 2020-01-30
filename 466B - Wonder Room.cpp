/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 466B - Wonder Room
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

inline void searchAns(Long &a, Long& b, Long area)
{
	Long auxB = b;
	Long currArea = LLONG_MAX;

	for (Long d = a; d * d <= area; ++d)
	{
		Long e = area / d;

		if (d * e < area)
			++e;

		if (auxB <= e and abs(d * e - area) < abs(currArea - area))
		{
			a = d;
			b = e;
			currArea = a * b;
		}
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long n, a, b;
	cin >> n >> a >> b;

	if (a * b < 6ll * n)
	{	
		if (min(a, b) <= min(6ll, n) and max(a, b) <= max(6ll, n))
		{
			if (a < b)
				a = min(6ll, n), b = max(6ll, n);
			else
				a = max(6ll, n), b = min(6ll, n);
		}
		else
		{
			if (a < b)
				searchAns(a, b, 6ll * n);
			else
				searchAns(b, a, 6ll * n);
		}
	}

	cout << a * b << "\n" << a << " " << b << "\n";

	return 0;
}