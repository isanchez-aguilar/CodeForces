/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 116B - Little Pigs and Wolves
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int neighbors[4][2] = {
		{-1,  0},
		{ 0, -1},
		{ 0,  1},
		{ 1,  0}
	};

	int h, w;
	cin >> h >> w;

	char grid[h + 1][w + 1];

	for (int i = 0; i < h; ++i)
		cin >> grid[i];
	int ans = 0;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (grid[i][j] == 'W')
			{
				for (int v = 0; v < 4; ++v)
				{
					int x = i + neighbors[v][0];
					int y = j + neighbors[v][1];

					if (x >= 0 and x < h and y >= 0 and y < w and grid[x][y] == 'P')
					{
						grid[x][y] = '.';
						++ans;
						break;
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
