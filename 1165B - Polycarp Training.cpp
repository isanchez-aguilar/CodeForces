/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1165B - Polycarp Training
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

	int days = 0;
	int problems = 1;

	sort(begin(a), end(a));

	for (int i = 0; i < n; ++i)
	{
		if (problems <= a[i])
			++days, ++problems;
	}	

	cout << days << "\n";

	return 0;
}