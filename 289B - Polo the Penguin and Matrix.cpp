/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 289B - Polo the Penguin and Matrix
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, d;
	cin >> n >> m >> d;

	const int size = m * n;
	int values[size];

	for (int i = 0; i < size; ++i)
		cin >> values[i];

	sort(values, values + size);

	if (m == 1 and n == 1)
		cout << "0\n";
	else
	{
		bool isPossible = true;
		int mod = values[0] % d;

		for (int i = 0; i < size; ++i)
		{
			if (values[i] % d != mod)
			{
				isPossible = false;
				break;
			}
		}

		if (not isPossible)
			cout << "-1\n";
		else
		{
			int totalMoves = 0;
			int median = values[(n * m) / 2];

			for (int i = 0; i < size; ++i)
				totalMoves += abs(values[i] - median) / d;

			cout << totalMoves << "\n";
		}
	}

	return 0;
}