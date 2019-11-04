/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 253B - Physics Practical
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int n;
	cin >> n;

	vector<int> freq(5001);
	
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;

		++freq[v];
	}

	vector<int> accum(5001);

	for (int i = 0; i < 5001; ++i)
	{
		accum[i] = freq[i];

		if (i > 0)
			accum[i] += accum[i - 1];
	}

	int ans = n + 1;

	for (int i = 5000; i > 0; --i)
	{

		if (freq[i] > 0)
		{
			int currDeleted = accum[i / 2 - (i % 2 == 0?1:0)];

			currDeleted += (accum[5000] - accum[i]);

			ans = min(ans, currDeleted);
		}

	}

	cout << ans << "\n";

	return 0;
}