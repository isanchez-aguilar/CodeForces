/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 148A- Insomnia cure
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> data(4);
	for (int i = 0; i < 4; ++i)
		cin >> data[i];

	int n;
	cin >> n;

	vector<bool> dragons(n + 1);

	for (int& v: data)
	{
		for (int i = v; i <= n; i += v)
			dragons[i] = true;
	}

	int ans = count(begin(dragons), end(dragons), true);

	cout << ans << "\n";

	return 0;
}
