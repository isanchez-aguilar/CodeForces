/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 600B - Queries about less or equal elements
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	int n;
	int m;
	cin >> n >> m;
	vector<int> b(m);
	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i)
		cin >> b[i];

	sort(a.begin(), a.end());
	
	for (int i = 0; i < m; ++i)
	{
		vector<int>::iterator j = lower_bound(a.begin(), a.end(), b[i] + 1);
		cout << (j - a.begin()) << (i + 1 == m?"\n":" ");
	}

	return 0;
}