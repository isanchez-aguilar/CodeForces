/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1102F - Elongated Matrix
*/
#include <bits/stdc++.h>

#define MAX_N 18
#define INF 1000000000

using namespace std;
using Matrix = vector< vector<int> >;

int n, m;
Matrix mat;
Matrix rowEdges;
Matrix colEdges;
int canMoveRows[MAX_N];
short memo[1 << MAX_N];
int usedRows[1 << MAX_N];

short dp(const int& unvisitedMask)
{
	short& m = memo[unvisitedMask];
	
	if (m == -1)
	{
		m = 0;
		usedRows[unvisitedMask] = 0;

		for (int i = 0; i < n; ++i)
		{
			const int newMask = unvisitedMask ^ (1 << i);
			
			if ((unvisitedMask >> i) & 1 and dp(newMask) and usedRows[newMask] & canMoveRows[i])
			{
				memo[unvisitedMask] = 1;
				usedRows[unvisitedMask] |= (1 << i);
			}
		}
	}
	
	return m;
}

inline bool isValid(int k)
{
	bool valid = false;

	for (int i = 0; i < n; ++i)
	{
		canMoveRows[i] = 0;

		for (int j = 0; j < n; ++j)
			canMoveRows[i] |= (1 << j) * (rowEdges[i][j] >= k);
	}

	for (int startRow = 0; startRow < n; ++startRow)
	{
		memset(memo, -1, sizeof memo);

		for (int endRow = 0; endRow < n; ++endRow)
		{
			memo[1 << endRow] = (startRow == endRow);
			usedRows[1 << endRow] = (1 << endRow);
		}

		const int allUnvisited = (1 << n) - 1;
		dp(allUnvisited);

		for (int endRow = 0; endRow < n; ++endRow)
		{
			if (colEdges[endRow][startRow] >= k and (usedRows[allUnvisited] >> endRow) & 1)
			{
				valid = true;
				break;
			}
		}
	}

	return valid;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	mat = Matrix(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> mat[i][j];
	}

	rowEdges = Matrix(n, vector<int>(n));
	colEdges = Matrix(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		rowEdges[i][i] = 0;

		for (int j = 0; j < n; ++j)
		{
			int minVal = INT_MAX;
		
			for (int k = 0; k < m; ++k)
				minVal = min(minVal, abs(mat[i][k] - mat[j][k]));

			rowEdges[i][j] = minVal;

			minVal = INT_MAX;

			for (int k = 0; k < m - 1; ++k)
				minVal = min(minVal, abs(mat[i][k] - mat[j][k + 1]));

			colEdges[i][j] = minVal;
		}
	}

	int k = 0;
	int leftVal = 0;
	int rightVal = INF;

	while (leftVal <= rightVal)
	{
		int middle = (leftVal + rightVal) / 2;

		if (isValid(middle))
		{
			k = middle;
			leftVal = middle + 1;
		}
		else
			rightVal = middle - 1;
	}

	cout << k << "\n";

	return 0;
}