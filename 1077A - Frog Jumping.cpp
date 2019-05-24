/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1077A - Frog Jumping
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	while (n--)
	{
		long long a;
		long long b;
		long long k;
		cin >> a >> b >> k;

		cout << ((k + 1) / 2) * a - k / 2 * b << "\n";
	}

	return 0;
}