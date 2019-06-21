/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1157E - Minimum Array
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

	multiset<int> b;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		b.insert(v);
	}

	for (int i = 0; i < n; ++i)
	{
		multiset<int>::iterator j = b.lower_bound(n - a[i]);

		if (end(b) == j)
			j = begin(b);

		cout << (a[i] + *j) % n << (i == n - 1?"\n":" ");
		b.erase(j);
	}

	return 0;
}