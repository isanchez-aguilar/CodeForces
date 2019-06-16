/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1176C - Lose it!
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<short, short> numberIndex;
	
	numberIndex[4] = 0;
	numberIndex[8] = 1;
	numberIndex[15] = 2;
	numberIndex[16] = 3;
	numberIndex[23] = 4;
	numberIndex[42] = 5;

	vector<int> prefixSequence(6);

	for (int i = 0; i < n; ++i)
	{
		short val;
		cin >> val;

		short index = numberIndex[val];

		if (index == 0)
			++prefixSequence[0];
		else if (prefixSequence[index - 1] > 0)
		{
			++prefixSequence[index];
			--prefixSequence[index - 1];
		}
	}

	cout << n - prefixSequence[5] * 6 << "\n";

	return 0;
}