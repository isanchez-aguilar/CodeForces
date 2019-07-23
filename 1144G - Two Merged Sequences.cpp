/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1144G - Two Merged Sequences
*/
#include <bits/stdc++.h>

#define MAX_VAL 200001
#define MIN_VAL -200001

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> memo[2];
	vector< vector<short> > prevType(2, vector<short>(n, -1));

	memo[0] = vector<int>(n, MAX_VAL);
	memo[1] = vector<int>(n, MIN_VAL);

	memo[0][0] = MIN_VAL;
	memo[1][0] = MAX_VAL;

	for (int i = 1; i < n; ++i)
	{
		if (a[i - 1] < a[i] and memo[1][i] < memo[1][i - 1])
		{
			prevType[0][i] = 0;
			memo[1][i] = memo[1][i - 1];
		}

		if (a[i] < memo[1][i - 1] and a[i - 1] < memo[0][i])
		{
			prevType[1][i] = 0;
			memo[0][i] = a[i - 1];
		}

		if (a[i] < a[i - 1] and memo[0][i - 1] < memo[0][i])
		{
			prevType[1][i] = 1;
			memo[0][i] = memo[0][i - 1];
		}

		if (memo[0][i - 1] < a[i] and memo[1][i] < a[i - 1])
		{
			prevType[0][i] = 1;
			memo[1][i] = a[i - 1];
		}
	}

	short currentSequence = -1;

	if (memo[0][n - 1] != MAX_VAL)
		currentSequence = 1;
	else if (memo[1][n - 1] != MIN_VAL)
		currentSequence = 0;

	string ansS = "NO";
	vector<short> ans(n);

	if (currentSequence != -1)
	{
		ansS = "YES";

		for (int i = n - 1; i >= 0; --i)
		{
			ans[i] = currentSequence;
			currentSequence = prevType[currentSequence][i];
		}
	}

	cout << ansS << "\n";

	if (ansS[0] == 'Y')
	{
		for (int i = 0; i < n; ++i)
			cout << (i > 0?" ":"") << ans[i];

		cout << "\n";
	}

	return 0;
}