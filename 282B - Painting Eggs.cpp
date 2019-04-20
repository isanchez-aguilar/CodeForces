/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 282B - Painting Eggs
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int currentDifference = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int gValue;
		int aValue;
		cin >> aValue >> gValue;

		if (currentDifference + aValue <= 500)
		{
			cout << "A";
			currentDifference += aValue;
		}
		else
		{
			cout << "G";
			currentDifference -= gValue;
		}
	}

	return 0;
}