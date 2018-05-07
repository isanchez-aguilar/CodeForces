/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 954A - Diagonal Walking
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if ((s[i] == 'R' and s[i + 1] == 'U') or (s[i] == 'U' and s[i + 1] == 'R'))
			++i;
		
		++cnt;
	}
	
	cout << cnt << "\n";
	return 0;
}
