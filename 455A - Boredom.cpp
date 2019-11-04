/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 455A - Boredom
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<Long> freq(100001);

	for (int i = 0; i < n; ++i)
	{
		Long v;
		cin >> v;
		++freq[v];
	}
	vector<Long> memo(100001);

	memo[1] = freq[1];

	for (Long i = 1; i < 100001; ++i)
		memo[i] = max(memo[i - 1], freq[i] * i + (i == 1?0:memo[i - 2]));

	cout << memo[100000] << "\n";

	return 0;
}
