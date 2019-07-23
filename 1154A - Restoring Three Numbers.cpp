/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 1154A - Restoring Three Numbers
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<Long> vals(4);

	for (int i = 0; i < 4; ++i)
		cin >> vals[i];

	sort(begin(vals), end(vals));

	Long abc = vals.back();
	vals.pop_back();

	Long a, b, c;


	do
	{
		c =  (vals[0] - vals[1] + vals[2]);

		if (c % 2ll == 0)
		{
			c /= 2ll;
			a = vals[0] - c;
			b = vals[2] - c;

			if (a >= 0 and b >= 0 and c >= 0 and a + b + c == abc)
				break;
		}
	} while(next_permutation(begin(vals), end(vals)));

	cout << a << " " << b << " " << c << "\n";

	return 0;
}