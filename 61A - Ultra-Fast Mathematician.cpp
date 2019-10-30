/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 61A - Ultra-Fast Mathematician
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string p, q;
	cin >> p >> q;

	string ans = p;

	for (int i = 0; i < int(p.length()); ++i)
		ans[i] = (p[i] == q[i]?'0':'1');

	cout << ans << "\n";	

	return 0;
}