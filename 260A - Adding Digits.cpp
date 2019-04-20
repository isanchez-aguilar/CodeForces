/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 260A - Adding Digits
*/
#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Number a, b, n;
	cin >> a >> b >> n;

	int nextDigit = -1;

	a *= 10;

	for (int i = 0; i <= 9; ++i)
	{
		if ((a + i) % b == 0)
		{
			nextDigit = i;
			break;
		}
	}

	if (nextDigit != -1)
		cout << a + nextDigit << setw(n) << setfill('0') << "\n";
	else
		cout << "-1\n";

	return 0;
}