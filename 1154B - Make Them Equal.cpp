/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1154B - Make Them Equal
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(begin(a), end(a));
	a.resize(unique(begin(a), end(a)) - begin(a));

	int ans = 0;

	if (a.size()  == 1)
		ans = 0;
	else if (a.size() <= 3)
	{
		if (a.size() == 2)
		{
			ans = a[1] - a[0];
			
			if (ans % 2 == 0)
				ans /= 2;
		}
		else
		{
			if (a[1] - a[0] == a[2] - a[1])
				ans = a[1] - a[0];
			else
				ans = -1;
		}
	}
	else
		ans = -1;

	cout << ans << "\n";

	return 0;
}