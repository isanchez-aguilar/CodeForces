/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 377A - Maze
*/
#include <bits/stdc++.h>

using namespace std;

const int neighbors[8][2] = {
	{-1, 0},
	{0, -1},
	{0, 1},
	{1, 0}
};

int dots = 0;
int currDfs = 0;
int h, w, blocks;
char maze[501][501];
bool visited[501][501];

void dfs(int i, int j)
{
	++currDfs;
	int children = 0;
	visited[i][j] = true;

	for (int m = 0; m < 8 and currDfs < dots - blocks; ++m)
	{
		int x = i + neighbors[m][0];
		int y = j + neighbors[m][1];

		if (x >= 0 and x < h and y >= 0 and y < w and maze[x][y] == '.' and not visited[x][y])
			dfs(x, y);
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> h >> w >> blocks;

	for (int i = 0; i < h; ++i)
		cin >> maze[i];

	memset(visited, false, sizeof visited);

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (maze[i][j] == '.')
				++dots;
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (maze[i][j] == '.')
			{
				dfs(i, j);
				i = h;
				break;
			}
		}
	}


	for (int i = 0; i < h and blocks > 0; ++i)
	{
		for (int j = 0; j < w and blocks > 0; ++j)
		{
			if (maze[i][j] == '.' and not visited[i][j])
			{
				--blocks;
				maze[i][j] = 'X';
			}
		}
	}

	for (int i = 0; i < h; ++i)
		cout << maze[i] << "\n";

	return 0;
}