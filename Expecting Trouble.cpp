#include <bits/stdc++.h>

using namespace std;
using Number = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	double p;

	getline(cin, s);
	cin >> p;

	double signs = 0.0;
	double ones = 0.0;

	for (char c : s)
	{
		if (c == '1')
			++ones;
		else if (c == '?')
			++signs;
	}

	cout << fixed << setprecision(5) << ((p * signs + ones) / (double)s.length()) << "\n";	

	return 0;
}