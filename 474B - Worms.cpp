/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 474B - Worms
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int worms[n];

	for (int i = 0; i < n; ++i)
	{
		int size;
		cin >> size;
		worms[i] = size + (i?worms[i - 1]:0);
	}
	
	int q;
	cin >> q;

	while (q--)
	{
		int p;
		cin >> p;

		int l = 0;
		int r = n;

		while (l < r)
		{
			int m = (l + r) >> 1;

			if (worms[m] < p)
				l = m + 1;
			else
				r = m;
		}

		cout << l + 1 << "\n";
	}

	return 0;
}