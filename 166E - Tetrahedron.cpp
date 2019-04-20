/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 166E - Tetrahedron
*/
#include <bits/stdc++.h>

#define MAX_STATE 4
#define MOD 1000000007
#define MAX_LENGTH 10000001

using namespace std;
using Number = int;

Number memo[MAX_STATE][MAX_LENGTH];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	memo[0][0] = 1;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < MAX_STATE; ++j)
		{
			memo[j][i] = 0;

			for (int k = 0; k < MAX_STATE; ++k)
			{
				if (j != k)
				{
					memo[j][i] += memo[k][i - 1];
					memo[j][i] %= MOD;
				}
			}
		}
	}

	cout << memo[0][n] << "\n";

	return 0;
}