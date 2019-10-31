/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 463C - Gargari and Bishops
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int n;
inline bool isInside(int x, int y)
{
	return x >= 0 and x < n and y >= 0 and y < n;
}
 
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<Long> sumDiagonal1(2 * n);
	vector<Long> sumDiagonal2(2 * n);
	vector< vector<Long> > m(n, vector<Long>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> m[i][j];
			sumDiagonal1[i + j] += m[i][j];
			sumDiagonal2[i - j + n - 1] += m[i][j];
		}
	}


	pair<int, int> posBishops[2];
	vector<Long> sumBishops = {-1, - 1};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int bishop = (i + j) % 2;
			Long currSum = sumDiagonal1[i + j] + sumDiagonal2[i - j + n - 1] - m[i][j];

			if (sumBishops[bishop] < currSum)
			{
				sumBishops[bishop] = currSum;
				posBishops[bishop] = {i + 1, j + 1};
			}
		}
	}


	cout << sumBishops[0] + sumBishops[1] << "\n";

	sort(begin(posBishops), end(posBishops));

	for (pair<int, int> v : posBishops)
		cout << v.first << " " << v.second << "\n";

	return 0;
}
