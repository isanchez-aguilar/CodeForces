/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1157D - N Problems During K Days
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

inline void printAns(const vector<Long>& ans)
{
	cout << "YES\n" << ans[0];

	for (int i = 1; i < (int)ans.size(); ++i)
		cout << " " << ans[i];

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Long n, k;
	cin >> n >> k;

	Long remaining = n - k * (k + 1) / 2ll;

	if (remaining < 0)
		cout << "NO\n";
	else
	{
		vector<Long> ans(k);
		const Long remainingPart = remaining / k;
		const Long startIndexRemaining = k - remaining % k;

		for (int i = 0; i < k; ++i)
			ans[i] = i + 1 + remainingPart + (i >= startIndexRemaining);

		if (remaining != k - 1)
			printAns(ans);
		else
		{
			if (k == 2 or k == 3)
				cout << "NO\n";
			else
			{
				if (k > 3)
					--ans[1], ++ans[k - 1];

				printAns(ans);
			}
		}
	}
	return 0;
}