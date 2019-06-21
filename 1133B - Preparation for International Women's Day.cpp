/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1133B - Preparation for International Women's Day
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	Long k;
	cin >> n >> k;
	vector<Long> m(k);

	for (int i = 0; i < n; ++i)
	{
		Long val;
		cin >> val;
		++m[val % k];
	}

	Long ans = m[0] / 2ll * 2ll;

	int leftIndex = 1;
	int rightIndex = k - 1;

	while (leftIndex <= rightIndex)
	{
		Long boxes = min(m[leftIndex], m[rightIndex]);

		if (leftIndex != rightIndex)
			boxes *= 2ll;
		else
			boxes = boxes / 2ll * 2ll;

		ans += boxes;

		++leftIndex;
		--rightIndex;
	}

	cout << ans << "\n";

	return 0;
}