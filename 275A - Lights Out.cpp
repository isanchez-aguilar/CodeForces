/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 275A - Lights Out
*/
#include <bits/stdc++.h>

using namespace std;

int neighbors[5][2] = {
	{-1,  0},
	{ 0,  0},
	{ 1,  0},
	{ 0, -1},
	{ 0,  1}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector< vector<short> > lights(3, vector<short>(3, 1));

	for (int i = 0; i < 3; ++i)
	{
		int t;
		for (int j = 0; j < 3; ++j)
		{
			cin >> t;

			if (t % 2 == 1)
			{
				for (int k = 0; k < 5; ++k)
				{
					int x = neighbors[k][0] + i;
					int y = neighbors[k][1] + j;

					if (x >= 0 and x < 3 and y >= 0 and y < 3)
						lights[x][y] ^= 1;
				}
			}
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cout << lights[i][j];

		cout << "\n";
	}

	return 0;
}