/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 118D - Caesar's Legions
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using Long = long long;

const Long MOD = 100000000ll;

int k1, k2;

Long memo[101][101][2];

Long solve(int n1, int n2, short currType)
{
	if (n1 == 0 and n2 == 0)
		return 1;

	if (currType == 0 and n1 == 0)
		return 0;

	if (currType == 1 and n2 == 0)
		return 0;

	Long& currMemo = memo[n1][n2][currType];

	if (currMemo == -1)
	{
		currMemo = 0;
		const int limitI = (currType == 0?min(k1, n1):min(k2, n2));

		for (int i = 1; i <= limitI; ++i)
		{
			int newN1 = n1;
			int newN2 = n2;

			if (currType == 0)
				newN1 -= i;
			else
				newN2 -= i;

			currMemo = (currMemo + solve(newN1, newN2, 1 - currType)) % MOD;
		}
	}

	return currMemo;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n1, n2;
	cin >> n1 >> n2 >> k1 >> k2;

	Long ans = 0;
	memset(memo, -1, sizeof memo);

	for (int currType = 0; currType < 2; ++currType)
		ans = (ans + solve(n1, n2, currType)) % MOD;

	cout << ans << "\n";


	return 0;
}
