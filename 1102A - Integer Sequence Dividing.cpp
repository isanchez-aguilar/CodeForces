/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1102A - Integer Sequence Dividing
*/
#include <bits/stdc++.h>

using namespace std;
using Long = unsigned long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Long n;
	cin >> n;

	const int m = n % 4;

	if (m == 1)
		cout << "1\n";
	else if (m == 3 or m == 0)
		cout << "0\n";
	else
		cout << "1\n";

	return 0;
}