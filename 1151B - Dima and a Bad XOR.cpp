/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1151B - Dima and a Bad XOR
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int rows, columns;
	cin >> rows >> columns;

	int currentXor = 0;
	int values[rows][columns];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cin >> values[i][j];

			if (j == 0)
				currentXor ^= values[i][0];			
		}
	}

	vector<int> ans(rows, 1);

	if (currentXor == 0)
	{
		for (int i = 0; i < rows and currentXor == 0; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				if (values[i][j] != values[i][0])
				{
					ans[i] = j + 1;
					currentXor ^= values[i][0];
					currentXor ^= values[i][j];

					break;
				}
			}
		}
	}

	if (currentXor == 0)
		cout << "NIE\n";
	else
	{
		cout << "TAK\n" << ans[0];

		for (int i = 1; i < rows; ++i)
			cout << " " << ans[i];

		cout << "\n"; 
	}

	return 0;
}