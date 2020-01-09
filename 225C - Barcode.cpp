/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 225C - Barcode
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
using Long = long;

const Long INF = 1000001;

int n, m, x, y;
Long accumColourCol[2][1001];
Long memo[1001][1001][2];

Long solve(int column, int width, int colour)
{
	if (column < 0)
		return 0;

	Long& dp = memo[column][width][colour];

	if (column - width + 1 < 0)
		dp = INF;

	if (dp == -1)
	{
		dp = 0;
		int prevColumn = column - width;

		dp = n * width - accumColourCol[colour][column];

		if (prevColumn > -1)
			dp += accumColourCol[colour][prevColumn];



		Long minPrev = INF;

		for (int prevWidth = x; prevWidth <= y and prevWidth <= prevColumn + 1; ++prevWidth)
		{
			Long currSol = solve(prevColumn, prevWidth, 1 - colour);

			minPrev = min(minPrev, currSol);
		}
		
		if (minPrev < INF or prevColumn == -1)
		{
			if (prevColumn != -1)
				dp += minPrev;
		}
		else
			dp = INF;
	}


	return dp;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> x >> y;

	char mat[n + 1][m + 1];

	for (int i = 0; i < n; ++i)
		cin >> mat[i];
	
	memset(accumColourCol, 0, sizeof accumColourCol);
	

	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			if (mat[i][j] == '#')
				++accumColourCol[1][j];
			else
				++accumColourCol[0][j];
		}

		if (j > 0)
		{
			accumColourCol[0][j] += accumColourCol[0][j - 1];
			accumColourCol[1][j] += accumColourCol[1][j - 1];
		}
	}


	Long ans = n * m + 1;
	memset(memo, -1, sizeof memo);

	for (int prevWidth = x; prevWidth <= y && prevWidth <= m; ++prevWidth)
	{
		for (int prevColour = 0; prevColour < 2; ++prevColour)
			ans = min(ans, solve(m - 1, prevWidth, prevColour));
	}

	cout << ans << "\n";

	return 0;
}
