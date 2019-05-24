    
/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1165A - Remainder
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;

	int ans = 0;

	if (s[n - y - 1] == '0')
		++ans;

	for (int i = n - y; i < n; ++i)
	{
		if (s[i] != '0')
			++ans;
	}

	for (int i = n - x; i < n - y - 1; ++i)
	{
		if (s[i] == '1')
			++ans;
	}

	cout << ans << "\n";	
	
	return 0;
}