/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1133A - Middle of the Contest
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char c;
	int h1, m1, h2, m2;

	cin >> h1 >> c >> m1;
	cin >> h2 >> c >> m2;

	int minutes1 = h1 * 60 + m1;
	int minutes2 = h2 * 60 + m2;

	int middleMinutes = (minutes1 + minutes2) / 2;

	cout << setw(2) << setfill('0') << middleMinutes / 60 << ":" << setw(2) << setfill('0') << middleMinutes % 60 << "\n";

	return 0;
}