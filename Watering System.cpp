#include <bits/stdc++.h>

using namespace std;
using Number = int;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	int s1;
	cin >> s1;

	int totalSum = s1;
	vector<int> pipes(n - 1);

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> pipes[i];
		totalSum += pipes[i];
	}

	sort(begin(pipes), end(pipes));

	int required = s1 * a / b;

	int deletedPipes = 0;
	int currentSum = totalSum - required;

	while (currentSum > 0)
	{
		vector<int>::iterator i = lower_bound(begin(pipes), end(pipes), currentSum);

		if (i == end(pipes))
			--i;

		currentSum -= *i;
		pipes.erase(i);
		++deletedPipes;
	}

	cout << deletedPipes << "\n";

	return 0;
}