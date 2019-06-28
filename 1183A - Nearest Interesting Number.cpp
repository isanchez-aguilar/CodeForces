/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1183A - Nearest Interesting Number
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int b;
	cin >> b;

	for (int i = b; i < 10000000; ++i)
	{
		int a = i;
		int sum = 0;
		while (a > 0)
		{
			sum += a % 10;
			a /= 10;
		}

		if (sum % 4 == 0)
		{
			cout << i << "\n";
			break;
		}
	}

	return 0;
}