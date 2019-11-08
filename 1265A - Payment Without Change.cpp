/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1265A - Payment Without Change
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	Long a, b, n, s;
	cin >> q;
	while (q--)
	{
		cin >> a >> b >> n >> s;

		s -= min(a * n, s / n * n);
 
		s -= min(s, b);

		if (s == 0)
			cout << "YES\n";
		else
			cout << "NO\n";	
	}

	return 0;
}