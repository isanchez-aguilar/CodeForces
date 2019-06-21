/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1157B - Long Number
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	vector<char> f(9);

	for (int i = 0; i < 9; ++i)
		cin >> f[i];

	int i = 0;
	string ans = "";

	while (i < (int)s.length())
	{
		int d = int(s[i]) - int('0') - 1;

		char c = f[d];

		if (s[i] < c)
			break;

		ans += s[i];
		++i;
	}

	while (i < (int)s.length())
	{
		int d = int(s[i]) - int('0') - 1;

		char c = f[d];

		if (c < s[i])
			break;

		ans += c;
		++i;
	}

	ans += s.substr(i, (int)s.length() - i);

	cout << ans << "\n";

	return 0;
}