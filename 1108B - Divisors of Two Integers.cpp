/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1108B - Divisors of Two Integers
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> divisors(n);

	for (int i = 0; i < n; ++i)
		cin >> divisors[i];

	sort(begin(divisors), end(divisors));

	int x = divisors.back();
	int auxX = x;

	set<int> divisorsX;
	divisorsX.insert(1);

	for (int i = 2; i <= auxX; ++i)
	{
		if (auxX % i == 0)
			divisorsX.insert(i);
	}

	int y = 1;

	for (int i = n - 1; i > -1; --i)
	{
		if (divisorsX.count(divisors[i]))
			divisorsX.erase(divisors[i]);
		else
		{
			y = divisors[i];
			break;
		}
	}

	cout << x << " " << y << "\n";

	return 0;
}