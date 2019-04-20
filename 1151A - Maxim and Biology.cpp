/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1151A - Maxim and Biology
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int minCost = INT_MAX;

	for (int i = 0; i <= n - 4; ++i)
	{
		int currentCost = 0;
		
		int path1 = abs((int)'A' - (int)s[i]);
		int path2 = 26 - path1;
		int costA = min(path1, path2);

		path1 = abs((int)'C' - (int)s[i + 1]);
		path2 = 26 - path1;
		int costC = min(path1, path2);

		path1 = abs((int)'T' - (int)s[i + 2]);
		path2 = 26 - path1;
		
		int costT = min(path1, path2);

		path1 = abs((int)'G' - (int)s[i + 3]);
		path2 = 26 - path1;
		int costG = min(path1, path2);

		currentCost = costA + costC + costT + costG;

		minCost = min(minCost, currentCost);
	}

	cout << minCost << "\n";

	return 0;
}