/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1157C - Increasing Subsequence (hard version)
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> vals(n);

	for (int i = 0; i < n; ++i)
		cin >> vals[i];

	int left = 0;
	int lastVal = 0;
	int right = n - 1;

	string ans = "";

	while (left <= right)
	{
		int leftVal = vals[left];
		int rightVal = vals[right];

		if (leftVal <= lastVal and rightVal <= lastVal)
			break;

		if (rightVal <= lastVal)
		{
			++left;
			ans += "L";
			lastVal = leftVal;
		}
		else if (leftVal <= lastVal)
		{
			--right;
			ans += "R";
			lastVal = rightVal;
		}
		else
		{
			if (leftVal < rightVal)
			{
				++left;
				ans += "L";
				lastVal = leftVal;
			}
			else if (rightVal < leftVal)
			{
				--right;
				ans += "R";
				lastVal = rightVal;
			}
			else
			{
				int i = 1;
				int j = 1;

				while (left + i <= right and vals[left + i - 1] < vals[left + i])
					++i;
				while (right - j >= left and vals[right - j + 1] < vals[right - j])
					++j;

				if (j < i)
				{
					++left;
					ans += "L";
					lastVal = leftVal;
				}
				else
				{
					--right;
					ans += "R";
					lastVal = rightVal;
				}
			}
		}
	}

	cout << ans.length() << "\n" << ans << "\n";

	return 0;
}