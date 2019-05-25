/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1151D - Stas and the Queue at the Buffet
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector< pair<Long, int> > c(n);
	vector< pair<Long, Long> > data(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> data[i].first >> data[i].second;
		
		c[i].second = i;
		c[i].first = data[i].first - data[i].second;
	}

	Long ans = 0;
	sort(begin(c), end(c), greater< pair<Long, int> >());

	for (int i = 0; i < n; ++i)
	{
		const int index = c[i].second;
		ans += (i + 1) * c[i].first + n * data[index].second - data[index].first;
	}

	cout << ans << "\n";

	return 0;
}