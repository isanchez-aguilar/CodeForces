/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 217A - Beautiful Year
*/
#include <bits/stdc++.h>

using namespace std;

inline bool hasUniqueDigits(int n)
{
	short usedDigits = 0;

	while (n > 0)
	{
		short d = n % 10;

		if (usedDigits & (1 << d))
			return false;

		usedDigits |= (1 << d);
		n /= 10; 
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int ans = n + 1;

	while (not hasUniqueDigits(ans))
		++ans;

	cout << ans << "\n";

	return 0;
}