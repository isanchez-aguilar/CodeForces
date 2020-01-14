/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 478C - Table Decorations
*/
#include <iostream>
#include <algorithm>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long r, g, b;
	cin >> r >> g >> b;

	const Long maxVal = max({r, g, b});

	if (2ll * (r + g + b - maxVal) <= maxVal)
		cout << r + g + b - maxVal << "\n";
	else
		cout << (r + g + b) / 3ll << "\n";

	return 0;
}
