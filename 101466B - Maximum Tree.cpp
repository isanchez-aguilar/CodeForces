/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 101466B - Maximum Tree
*/
#include <bits/stdc++.h>

using namespace std;
using Number = unsigned long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<Number> vals(n);
	
	for (int i = 0; i < n; ++i)
		cin >> vals[i];

	sort(begin(vals), end(vals), greater<Number>());
	
	Number ans = 1;
	Number prevProduct = 1;
	for (int i = 0; i < n; ++i)
	{
		prevProduct *= vals[i];
		ans += prevProduct;
	}

	cout << ans << "\n";

	return 0;
}