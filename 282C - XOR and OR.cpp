/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 282C - XOR and OR
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	if ((int)a.length() != (int)b.length())
		cout << "NO\n";
	else
	{
		int zerosOfA = count(begin(a), end(a), '0');
		int zerosOfB = count(begin(b), end(b), '0');

		if (a != b and (zerosOfB == (int)b.length() or zerosOfA == (int)a.length()))
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}