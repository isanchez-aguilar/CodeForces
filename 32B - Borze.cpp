/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 32B - Borze
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	string ans = "";
	int i = 0;

	while (i < int(s.length()))
	{
		if (s[i] == '.')
			ans += '0', ++i;
		else if (s[i] != s[i + 1])
			ans += '1', i += 2;
		else
			ans += '2', i += 2;
	}

	cout << ans << "\n";

	return 0;
}