/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 493D - Vasya and Chess
*/
#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n % 2 == 0)
		cout << "white\n1 2 \n";
	else
		cout << "black\n";

	return 0;
}