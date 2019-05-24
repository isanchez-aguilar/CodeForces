/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 101466H - Logo
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int size;
	cin >> size;

	cout << "*";

	for (int i = 0; i < size - 2; ++i)
		cout << " ";

	cout << "* *";

	for (int i = 0; i < size - 2; ++i)
		cout << "*";

	cout << "*\n";

	for (int i = 0; i < size - 2; ++i)
	{
		cout << "*";

		for (int j = 0; j < size - 2; ++j)
			cout << " ";

		cout << "* *";

		for (int j = 0; j < size - 2; ++j)
			cout << " ";

		cout << "*\n";
	}

	cout << "*";

	for (int i = 0; i < size - 2; ++i)
		cout << "*";

	cout << "* *";

	for (int i = 0; i < size - 2; ++i)
		cout << " ";

	cout << "*\n";

	return 0;
}