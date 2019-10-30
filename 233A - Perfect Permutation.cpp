/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 233A - Perfect Permutation
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

	vector<int> ans(1);

	if (n % 2 == 1)
		ans[0] = -1;
	else
	{
		ans.resize(n);
		iota(begin(ans), end(ans), 1);
	}

	reverse(begin(ans), end(ans));

	for (int& v : ans)
		cout << v << " ";

	return 0;
}