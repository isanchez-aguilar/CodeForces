/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 248A - Cupboards
*/
#include <bits/stdc++.h>
    
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector< pair<short, short> > a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;

	int leftOnes = 0;
	int rightOnes = 0;

	for (pair<short, short>& v : a)
	{
		leftOnes += v.first;
		rightOnes += v.second;
	}

	int ans = min(n - leftOnes, leftOnes);
	ans += min(n - rightOnes, rightOnes);

	cout << ans << "\n";

	return 0;
}