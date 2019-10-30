/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 144A - Arrival of the General
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

	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int maxPos = 0;

	for (int i = 0; i < n; ++i)
	{
		if (a[maxPos] < a[i])
			maxPos = i;
	}

	int minPos = n - 1;

	for (int i = n - 1; i >= 0; --i)
	{
		if (a[i] < a[minPos])
			minPos = i;
	}

	int ans = maxPos + (n - 1 - minPos);

	if (minPos < maxPos)
		--ans;

	cout << ans << "\n";

	return 0;
}