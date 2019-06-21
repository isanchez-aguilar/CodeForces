/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1157G - Inverse of Rows and Columns
*/
#include <bits/stdc++.h>

using namespace std;
using Row = vector<short>;
using Matrix = vector<Row>;

inline void invertRow(Matrix& m, int r)
{
	for (int i = 0; i < (int)m[r].size(); ++i)
		m[r][i] ^= 1;

	return;
}

inline void invertColumn(Matrix& m, int c)
{
	for (int i = 0; i < (int)m.size(); ++i)
		m[i][c] ^= 1;

	return;
}

inline void setFirstRow(Matrix& m, string& opC, const int preffix0)
{
	for (int i = 0; i < (int)m[0].size(); ++i)
	{
		if ((i < preffix0 and m[0][i] == 1) or (preffix0 <= i and m[0][i] == 0))
		{
			opC[i] = '1';
			invertColumn(m, i);
		}
	}

	return;
}

inline short getRowSum(const Matrix& m, int r)
{
	return accumulate(begin(m[r]), end(m[r]), 0);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	Matrix mat(n, Row(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> mat[i][j];
	}

	string ans = "NO", ansR, ansC;

	for (int preffix0 = 0; preffix0 <= m; ++preffix0)
	{
		Matrix auxM = mat;
		string opR(n, '0');
		string opC(m, '0');

		setFirstRow(auxM, opC, preffix0);

		bool isPossible = true;

		if (preffix0 < m)
		{
			for (int i = 1; i < n; ++i)
			{
				short rowSum = getRowSum(auxM, i);

				if (rowSum == 0)
				{
					opR[i] = '1';
					invertRow(auxM, i);
				}
				else if (rowSum != m)
				{
					isPossible = false;
					break;
				}
			}
		}
		else
		{
			int transitionRow = -1;

			for (int i = 1; i < n and isPossible; ++i)
			{
				short rowSum = getRowSum(auxM, i);

				if (rowSum != 0 and rowSum != m)
				{
					if (transitionRow == -1)
						transitionRow = i;
					else
					{
						isPossible = false;
						break;
					}
				}
			}

			if (isPossible)
			{
				if (transitionRow == -1)
				{
					for (int i = 0; i < n; ++i)
					{
						short rowSum = getRowSum(auxM, i);

						if (rowSum == 0)
						{
							opR[i] = '1';
							invertRow(auxM, i);
						}
					}
				}
				else
				{
					if (auxM[transitionRow][0] == 1)
					{
						opR[transitionRow] = '1';
						invertRow(auxM, transitionRow);
					}

					for (int i = 1; i < m; ++i)
					{
						if (auxM[transitionRow][i - 1] > auxM[transitionRow][i])
						{
							isPossible = false;
							break;
						}
					}

					if (isPossible)
					{
						for (int i = 1; i < transitionRow; ++i)
						{
							short rowSum = getRowSum(auxM, i);

							if (rowSum == m)
							{
								opR[i] = '1';
								invertRow(auxM, i);
							}
						}

						for (int i = transitionRow + 1; i < n; ++i)
						{
							short rowSum = getRowSum(auxM, i);

							if (rowSum == 0)
							{
								opR[i] = '1';
								invertRow(auxM, i);
							}
						}
					}
				}
			}
		}		

		if (isPossible)
		{
			ans = "YES";
			ansR = opR;
			ansC = opC;
			break;
		}
	}

	cout << ans << "\n";

	if (ans[0] == 'Y')
		cout << ansR << "\n" << ansC << "\n";

	return 0;
}