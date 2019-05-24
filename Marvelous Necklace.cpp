#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int a = 0;
	int b = 0;

	for (char c : s)
	{
		if (c == 'A')
			++a;
		else
			++b;
	}

	if (a % 2 != 0 or b % 2 != 0)
		cout << "NO\n";
	else
	{
		s += s;

		int halfA = a / 2;
		int halfB = b / 2;
		const int size = (int)s.length();
		const int realSize = size / 2;
		vector<int> accumulateA(size + 1);
		vector<int> accumulateB(size + 1);

		accumulateA[0] = 0;
		accumulateB[0] = 0;

		for (int i = 1; i <= size; ++i)
		{
			accumulateA[i] = accumulateA[i - 1];
			accumulateB[i] = accumulateB[i - 1];
			
			if (s[i - 1] == 'A')
				++accumulateA[i];
			else
				++accumulateB[i];
		}

		int left = 0;
		int right = 0;
		int currentA = 0;
		int currentB = 0;
		pair<int, int> ans(-1, -1);

		while (left <= right and left <= size and right <= size)
		{
			int currentA = accumulateA[right] - accumulateA[left - (left == 0?0:1)];
			int currentB = accumulateB[right] - accumulateB[left - (left == 0?0:1)];

			
			if (currentA == halfA and currentB == halfB)
			{
				ans.first = left;
				ans.second = right + 1;
				ans.first %= (realSize + 1);
				ans.second %= (realSize + 1);

				if (ans.first > ans.second)
					swap(ans.first, ans.second);

				if (ans.first == 0)
					++ans.first;

				break;
			}


			if (currentA < halfA)
				++right;
			else if (currentA > halfA)
				++left;

			if (currentB < halfB)
				++right;
			else if (currentB > halfB)
				++left;
		}

		if (ans.first != -1)
		{
			cout << "YES\n";
			cout << ans.first << " " << ans.second << "\n";
		}
		else
			cout << "NO\n";
	}

	return 0;
}