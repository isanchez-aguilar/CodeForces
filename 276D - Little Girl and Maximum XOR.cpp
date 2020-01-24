/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 276D - Little Girl and Maximum XOR
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

string lBin = "";
string rBin = "";
Long memo[65][2][2][2][2];

Long dp(int idx, short flagA1, short flagA2, short flagB1, short flagB2)
{
	if (idx == int(rBin.length()))
		return 0;

	Long& currMemo = memo[idx][flagA1][flagA2][flagB1][flagB2];

	if (currMemo == -1)
	{
		currMemo = 0;
		Long initA = 0;
		Long initB = 0;

		Long endA = 1;
		Long endB = 1;

		if (flagA1)		
			initA = 0;
		else
			initA = lBin[idx] - '0';

		if (flagA2)
			endA = 1;
		else
			endA = rBin[idx] - '0';

		if (flagB1)
			initB = 0;
		else
			initB = lBin[idx] - '0';

		if (flagB2)
			endB = 1;
		else
			endB = rBin[idx] - '0';
		
		for (int i = initA; i <= endA; ++i)
		{
			for (int j = initB; j <= endB; ++j)
			{
				Long currAns = 0;
				Long currBit = i ^ j;
				int pos = int(rBin.length()) - idx - 1;

				if (currBit)
					currAns += (1ll << pos);
				
				short newFlagA1 = flagA1 | (i > (lBin[idx] - '0'));
				short newFlagA2 = flagA2 | (i < (rBin[idx] - '0'));

				short newFlagB1 = flagB1 | (j > (lBin[idx] - '0'));
				short newFlagB2 = flagB2 | (j < (rBin[idx] - '0'));


				currMemo = max(currMemo, currAns + dp(idx + 1, newFlagA1, newFlagA2, newFlagB1, newFlagB2));
			}
		}
	}

	return currMemo;
}

void toBinary(Long l, Long r)
{
	string ans = "";
	Long auxR = r;
	Long auxL = l;

	while (auxR > 0)
	{
		lBin += (auxL & 1ll?"1":"0");
		rBin += (auxR & 1ll?"1":"0");
		
		auxL >>= 1ll;
		auxR >>= 1ll;
	}

	reverse(begin(lBin), end(lBin));
	reverse(begin(rBin), end(rBin));

	return;
}

Long solve(Long l, Long r)
{
	if (l == r)
		return 0;

	memset(memo, -1, sizeof memo);
	toBinary(l, r);

	return dp(0, 0, 0, 0, 0);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long l, r;
	cin >> l >> r;

	cout << solve(l, r) << "\n";

	return 0;
}