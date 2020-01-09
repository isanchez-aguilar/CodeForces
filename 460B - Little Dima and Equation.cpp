/*
*	User: Isanchez_Aguilar
*	Problem: CodeForces 460B - Little Dima and Equation
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
using Long = long long;

Long fastPow(Long a, Long p)
{
	Long ans = 1;

	while (p > 0)
	{
		if ((p & 1ll) == 1ll)
			ans *= a;

		p >>= 1ll;
		a *= a;
	}

	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Long a, b, c;
	cin >> a >> b >> c;

	vector<Long> ans;

	for (Long sx = 0; sx < 82; ++sx)
	{
		Long x = b * fastPow(sx, a) + c;

		Long aux = x;
		Long sum = 0;

		while (aux > 0)
		{
			sum += aux % 10ll;
			aux /= 10ll;
		}

		if (sum == sx and x > 0 and x < 1000000000ll)
			ans.emplace_back(x);
	}

	sort(begin(ans), end(ans));

	cout << ans.size() << "\n";

	for (auto& x : ans)
		cout << x << " ";

	cout << "\n";

	return 0;
}
